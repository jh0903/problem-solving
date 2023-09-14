#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int si, ans;
vector<int> v;

int solution(int k, vector<vector<int>> dungeons) {
    si = dungeons.size();
    for(int i = 0;i < si;i++) v.push_back(i);
    do {
        int cur_fatigue = k;
        int cnt = 0;
        for(int i=0;i<si;i++){
            if(cur_fatigue < dungeons[v[i]][0]) break;
            cnt++;
            cur_fatigue -= dungeons[v[i]][1];
        }
        ans = max(ans, cnt);
    } while(next_permutation(v.begin(), v.end()));
    
    
    return ans;
}