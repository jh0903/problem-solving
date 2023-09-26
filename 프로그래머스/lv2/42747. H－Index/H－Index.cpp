#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int sum[10001];

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int citation: citations){
        sum[citation]++;
    }
    for(int i=9999;i>=0;i--){
        sum[i] += sum[i+1];
        if(i <= sum[i]){
            answer = i;
            break;
        }
    }
    
    return answer;
}