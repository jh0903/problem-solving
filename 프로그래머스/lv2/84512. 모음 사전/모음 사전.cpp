#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int cnt = 1;
char vow[5] = {'A', 'E', 'I', 'O', 'U'};
map<string, int> mp;

void dfs(int c, string cur){
    if(c == 5) return;
    for(int i=0;i<5;i++){
        mp[cur + vow[i]] = cnt++;
        dfs(c+1, cur + vow[i]);
    }
}

int solution(string word) {
    int answer = 0;
    dfs(0, "");
    
    return mp[word];
}