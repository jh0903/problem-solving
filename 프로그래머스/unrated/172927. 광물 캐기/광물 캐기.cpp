#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> miToInt;
map<int, int> mp;
int vis[3];
int fatigue[3][3] = {{1,1,1}, {5,1,1}, {25, 5, 1}};
int answer = 987654321;
vector<string> mi;

void dfs(int c, int sum){
    if(c >= mi.size()){
        answer = min(answer, sum);
        return;
    }
    for(int i=0;i<3;i++){
        if(!vis[i]) continue;
        vis[i]--;
        int cnt = 0;
        for(int j = 0;j<5 && j + c<mi.size();j++){
            cnt += fatigue[i][miToInt[mi[j + c]]];
        }
        dfs(c+5, sum + cnt);
        vis[i]++;
    }
    bool chk = false;
    for(int i=0;i<3;i++){
        if(vis[i]) chk = true;
    }
    if(!chk) answer = min(answer, sum);
}

int solution(vector<int> picks, vector<string> minerals) {
    for(int i=0;i<3;i++) vis[i] = picks[i];
    mi = minerals;
    miToInt["dia"] = 0;miToInt["iron"] = 1;miToInt["stone"] = 2;
    dfs(0, 0);
    
    return answer;
}