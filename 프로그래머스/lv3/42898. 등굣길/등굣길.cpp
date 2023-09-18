#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[101][101];
bool arr[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(vector<int> v : puddles) {
        arr[v[1]][v[0]] = 1;
    }
    for(int i=1;i<=n;i++) {
        if(arr[i][1]) break;
        dp[i][1] = 1;
    }
    for(int i=1;i<=m;i++){
        if(arr[1][i]) break;
        dp[1][i] = 1;
    } 
    
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(arr[i][j]) continue;
            dp[i][j] =(dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    return dp[n][m];
}