#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    while(!deliveries.empty() && !deliveries[deliveries.size()-1]){
        deliveries.pop_back();
    }
    while(!pickups.empty() && !pickups[pickups.size()-1]){
        pickups.pop_back();
    }
    while(!deliveries.empty() || !pickups.empty()){
        long long d_dist = deliveries.size(), p_dist = pickups.size();
        answer+= max(d_dist, p_dist) * 2;
        long long sum = 0;
        while(!deliveries.empty()){
            int si = deliveries.size();
            if(sum + deliveries[si-1] > cap){
                deliveries[si-1] -= (cap-sum);
                break;
            }
            sum+=deliveries[si-1];
            deliveries.pop_back();
        } 
        sum = 0;
        while(!pickups.empty()){
            int si = pickups.size();
            if(sum + pickups[si-1] > cap){
                pickups[si-1] -= (cap-sum);
                break;
            }
            sum+=pickups[si-1];
            pickups.pop_back();
        }
    }
    
    return answer;
}