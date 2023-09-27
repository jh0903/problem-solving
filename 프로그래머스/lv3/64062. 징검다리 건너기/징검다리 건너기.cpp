#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int,int>> pq; // 값, 위치

int solution(vector<int> stones, int k) {
    int answer = 200000001;
    for(int i=0;i<k;i++){
        pq.push({stones[i], i});
    }
    answer = min(answer, pq.top().first); 
    for(int en = k; en < stones.size(); en++){
        int st = en - k + 1;
        pq.push({stones[en], en});
        while(!(st <= pq.top().second && pq.top().second <= en)){
            pq.pop();
        }
        answer = min(answer, pq.top().first);
    }
    
    
    return answer;
}