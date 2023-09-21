#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int,int>> st; // 숫자, 위치
    for(int i=prices.size() - 1;i>=0;i--){
        if(st.empty()){
            answer[i] = 0;
            st.push({prices[i], i});
        }
        else {
            if(st.top().first < prices[i]){
                answer[i] = st.top().second - i;
                st.push({prices[i], i});
            }
            else {
                int last;
                while(!st.empty() && st.top().first >= prices[i]){
                    st.pop();
                }
                if(st.empty()) last = prices.size()-1;
                else last = st.top().second;
                answer[i] = last - i;
                st.push({prices[i], i});
            }
        }
    }
    
    return answer;
}