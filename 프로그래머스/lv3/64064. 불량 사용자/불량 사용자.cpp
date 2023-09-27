#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> mp;

int answer;
bool vis[10];

void func(vector<string> &ban, vector<string> &user, int b_cur){
    if(b_cur == ban.size()){
        string tmp = "";
        for(int i=0;i<user.size();i++) tmp += to_string(vis[i]);
        if(mp[tmp]) return;
        mp[tmp] = 1;
        answer++;
        return;
    }
    for(int i=0;i<user.size();i++){
        if(vis[i] || (user[i].size() != ban[b_cur].size())) continue;
        bool chk = true;
        for(int j=0;j<ban[b_cur].size();j++){
            if(ban[b_cur][j] == '*') continue;
            if(ban[b_cur][j] != user[i][j]) chk = false;
        }
        if(chk){
            vis[i] = 1;
            func(ban, user, b_cur + 1);
            vis[i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    func(banned_id, user_id, 0);
    
    
    return answer;
}