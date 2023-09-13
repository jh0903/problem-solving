#include <iostream>
#include <string>
using namespace std;

bool dp[2505][2505];

int solution(string s){
    int answer = 0;
    for(int x = 0; x < s.size(); x++){
        for(int st = 0; st < s.size(); st++){
            int en = st + x;
            if(s[st] == s[en]){
                if(st+1>en-1)dp[st][en] = 1;
                else if(dp[st+1][en-1]) dp[st][en] = 1;
                if(dp[st][en]) answer = max(answer, en-st+1);
            }
        }
    }
    
    return answer;
}