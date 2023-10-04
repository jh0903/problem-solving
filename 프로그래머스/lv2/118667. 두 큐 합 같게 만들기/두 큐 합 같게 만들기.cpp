#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<long long> q1, q2;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0, sum2 = 0;
    for(int i=0;i<queue1.size();i++){
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    int si = queue1.size();
    for(int i=0; i < si * 3 && sum1 != sum2; i++){
        answer++;
        if(sum1 < sum2){
            int top = q2.front(); q2.pop();
            sum2 -= top; sum1 += top;
            q1.push(top);
        }
        else {
            int top = q1.front(); q1.pop();
            sum1 -= top; sum2 += top;
            q2.push(top);
        }
    }
    if(sum1 != sum2) answer = -1;
    
    return answer;
}