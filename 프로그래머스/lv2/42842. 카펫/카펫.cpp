#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int garo=yellow;garo>0;garo--){
        if(yellow % garo != 0) continue;
        int sero = yellow / garo;
        if(sero * 2 + (garo + 2) * 2 == brown){
            answer.push_back(garo + 2);
            answer.push_back(sero + 2);
            break;
        }
    }
    return answer;
}