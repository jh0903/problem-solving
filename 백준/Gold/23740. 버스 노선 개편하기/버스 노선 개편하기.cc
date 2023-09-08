#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include <tuple>
using namespace std;

int N;
vector<tuple<int, int, int>> v;
tuple<int, int, int> ans[200001];

int main(void) {
	ios::ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0;i < N;i++) {
		int S, E, C;
		cin >> S >> E >> C;
		v.push_back({ S, E, C });
	}
	sort(v.begin(), v.end());
	ans[0] = v[0];
	int cnt = 0;
	for (int i = 1;i < N;i++) {
		int s, e, c;
		tie(s, e, c) = v[i];
		if (s <= get<1>(ans[cnt])) { // 합치기
			if (get<1>(ans[cnt]) < e) get<1>(ans[cnt]) = e;
			if (get<2>(ans[cnt]) > c) get<2>(ans[cnt]) = c;
		}
		else {
			ans[++cnt] = v[i];
		}
	}
	cout << ++cnt<<'\n';
	for (int i = 0;i < cnt;i++) 
		cout << get<0>(ans[i]) << ' ' << get<1>(ans[i]) << ' ' << get<2>(ans[i]) << '\n';
	return 0;
}