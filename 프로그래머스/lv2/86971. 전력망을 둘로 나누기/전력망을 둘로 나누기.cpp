#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for(int i=0;i<wires.size();i++){
        vector<int> adj[105];
        vector<int> nums;
        for(int j=0;j<wires.size();j++){
            if(j==i) continue;
            int st = wires[j][0], en = wires[j][1];
            adj[st].push_back(en);
            adj[en].push_back(st);
        }
        queue<int> q;
        bool vis[101] = {0};
        for(int v = 1;v<=n;v++){
            if(vis[v]) continue;
            q.push(v);
            vis[v] = 1;
            int cnt = 0;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                cnt++;
                for(int nxt : adj[cur]){
                    if(vis[nxt]) continue;
                    q.push(nxt); vis[nxt] = 1;
                }
            }
            nums.push_back(cnt);
        }
        answer = min(answer, abs(nums[0] - nums[1]));
    }
    return answer;
}