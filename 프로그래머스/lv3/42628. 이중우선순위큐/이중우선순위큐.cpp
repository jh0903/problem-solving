#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

priority_queue<int> pq_desc;
priority_queue<int, vector<int>, greater<int>> pq_asc;
map<string, int> mp;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    answer.push_back(0); answer.push_back(0);
    for(string o : operations){
        if(o[0] == 'I'){
            int num = stoi(o.substr(2, sizeof(o)));
            pq_asc.push(num);
            pq_desc.push(num);
            mp[to_string(num)]++;
        }else {
            if(o[2] == '1'){
                while(!pq_desc.empty()){
                    int mx = pq_desc.top(); pq_desc.pop();
                    if(mp[to_string(mx)]){
                        mp[to_string(mx)]--;
                        break;
                    }
                }
            }
            else {
                while(!pq_asc.empty()){
                    int mi = pq_asc.top(); pq_asc.pop();
                    if(mp[to_string(mi)]){
                        mp[to_string(mi)]--;
                        break;
                    }
                }
            }
        }
    }
    while(!pq_desc.empty()){
        int cur = pq_desc.top();
        if(mp[to_string(cur)]) {
            answer[0] = cur;
            break;
        }
        else pq_desc.pop();
    }
    while(!pq_asc.empty()){
        int cur = pq_asc.top();
        if(mp[to_string(cur)]) {
            answer[1] = cur;
            break;
        }
        else pq_asc.pop();
    }
    return answer;
}