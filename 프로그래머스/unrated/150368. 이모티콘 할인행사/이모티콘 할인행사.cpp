#include <string>
#include <vector>
#include <iostream>
using namespace std;

int per[4] = {10, 20, 30, 40};
int sale[10]; // 각 이모티콘이 얼마 할인하는지
int ans1, ans2;

void dfs(int c, vector<vector<int>> &users, vector<int> &emo){
    if(c == emo.size()){
        int tmp1 = 0, tmp2 = 0;
        for(int i=0;i<users.size();i++){
            int sum = 0;
            for(int j=0;j<emo.size();j++){
                if(sale[j] >= users[i][0]){
                    sum += emo[j] * (100-sale[j]) / 100;
                }
            }
            if(sum >= users[i][1]) {
                tmp1++;
            }
            else tmp2 += sum;
        }
        if(ans1 < tmp1) {
            ans1 = tmp1;
            ans2 = tmp2;
        }
        else if(ans1 == tmp1){
            if(ans2 < tmp2) ans2 = tmp2;
        }
        return;
    }
    for(int i=0;i<4;i++){
        sale[c] = per[i];
        dfs(c+1, users, emo);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    dfs(0, users, emoticons);
    answer.push_back(ans1); answer.push_back(ans2);
    return answer;
}