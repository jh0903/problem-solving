#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    deque<char> dq;
    int cnt = 0;
    for(int i=0;i<number.size();i++){
        if(cnt == k){
            dq.push_back(number[i]);
            continue;
        }
        if(dq.empty()){
            dq.push_back(number[i]);
        }
        else {
            while(!dq.empty() && dq.back() < number[i] && cnt != k){
                cnt++;
                dq.pop_back();
            }
            dq.push_back(number[i]);
        }
    }
    for(int i=0;i<number.size() - k; i++) answer += dq[i];
    
    return answer;
}