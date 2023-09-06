#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

map<string, int> play_cnt;
map<string, vector<pair<int,int>>> songs; //고유번호, 재생횟수

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first<b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<genres.size();i++){
        play_cnt[genres[i]]+= plays[i];
        songs[genres[i]].push_back({i, plays[i]});
    }
    priority_queue<pair<int, string>> pq;
    for(auto iter : play_cnt){
        pq.push({iter.second, iter.first});
        sort(songs[iter.first].begin(), songs[iter.first].end(), comp);
    }
    while(!pq.empty()){
        string cur_genre = pq.top().second; pq.pop();
        for(int i=0;i<2;i++){
            answer.push_back(songs[cur_genre][i].first);
            if(songs[cur_genre].size()<2) break;
        }
    }
    
    return answer;
}
