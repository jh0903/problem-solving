#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool vis[101];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int,int>> adj[101]; // 비용, 섬
    for(int i=0;i<costs.size();i++){
        adj[costs[i][0]].push_back({costs[i][2], costs[i][1]});
        adj[costs[i][1]].push_back({costs[i][2], costs[i][0]});
    }
    pq.push({0, 0});
    while(!pq.empty()){
        int cur_v = pq.top().second; 
        int cur_cost = pq.top().first; pq.pop();
        if(vis[cur_v]) continue;
        answer += cur_cost;
        vis[cur_v] = 1;
        for(pair<int,int> nxt: adj[cur_v]){
            if(vis[nxt.second]) continue;
            pq.push(nxt);
        }
    }
    return answer;
}