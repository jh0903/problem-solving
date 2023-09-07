#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int n;
map<string, int> sToi;
vector<string> adj[10005];
map<pair<int, int>, int> t_order; // 몇 번째 티켓인지
int used[10005]; // 티켓 사용 여부
vector<string> answer;
vector<string> tmp(100005);

void dfs(int c, int cur){
    if(c == n){
        if(answer.size() == 1){
            answer.push_back(tmp[0]);
            for(int i=1;i<n;i++) answer.push_back(tmp[i]);
        }
        return;
    }
    for(string nxt: adj[cur]){
        int cur_ticket = t_order[ {cur, sToi[nxt]} ];
        if(!used[cur_ticket]) continue;
        used[cur_ticket]--;
        tmp[c] = nxt;
        dfs(c+1, sToi[nxt]);
        used[cur_ticket]++;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int cnt = 1;
    n = tickets.size();
    for(int i=0;i<tickets.size();i++){
        string st = tickets[i][0], en = tickets[i][1];
        if(!sToi[st]) sToi[st] = cnt++;
        if(!sToi[en]) sToi[en] = cnt++;
        adj[sToi[st]].push_back(en);
        if(!t_order[{sToi[st], sToi[en]}]) t_order[{sToi[st], sToi[en]}] = i;
        used[t_order[{sToi[st], sToi[en]}]]++;
    }
    // 알파벳순으로 정렬
    for(int i=0;i<cnt;i++) sort(adj[i].begin(), adj[i].end());
    // ICN에서 출발
    answer.push_back("ICN");
    for(int i=0;i<adj[sToi["ICN"]].size();i++){
        string nxt = adj[sToi["ICN"]][i];
        used[t_order[{sToi["ICN"], sToi[nxt]}]]--;
        tmp[0] = nxt;
        dfs(1, sToi[nxt]);
        used[t_order[{sToi["ICN"], sToi[nxt]}]]++;
    }
    
    return answer;
}