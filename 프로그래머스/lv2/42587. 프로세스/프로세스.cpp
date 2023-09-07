#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

priority_queue<int> pq;
queue<pair<int,int>> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i], i}); 
        pq.push(priorities[i]);
    }
    while(!pq.empty()){
        answer++;
        int mx = pq.top(); pq.pop(); // 현재 최댓값
        while(!q.empty()){
            pair<int,int> cur = q.front(); q.pop();
            if(cur.first == mx) {
                if(cur.second == location){
                    return answer;
                }
                break;
            }
            q.push(cur);
        }
    }
    return answer;
}