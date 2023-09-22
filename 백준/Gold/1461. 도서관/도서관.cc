#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, ans;
vector<int> neg, pos;

int main(void) {
	ios::ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	for (int x, i = 0;i < N;i++) {
		cin >> x;
		if (x < 0) neg.push_back(x);
		else pos.push_back(x);
	}
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());
	if (!neg.empty() && pos.empty()) {
		ans += -neg[0];
		for (int i = M;i < neg.size();i += M) {
			ans += -neg[i] * 2;
		}
	}
	else if (neg.empty() && !pos.empty()) {
		ans += pos[pos.size() - 1];
		for (int i = pos.size() - 1 - M;i >= 0;i-=M) {
			ans += pos[i] * 2;
		}
	}
	else {
		if (-neg[0] > pos[pos.size() - 1]) {
			ans += -neg[0];
			for (int i = M;i < neg.size();i += M) {
				ans += -neg[i] * 2;
			}
			for (int i = pos.size() - 1;i >= 0;i -= M) {
				ans += pos[i] * 2;
			}
		}
		else {
			ans += pos[pos.size() - 1];
			for (int i = 0;i < neg.size();i += M) {
				ans += -neg[i] * 2;
			}
			for (int i = pos.size() - 1 - M;i >= 0;i -= M) {
				ans += pos[i] * 2;
			}
		}
	}
	cout << ans;
	return 0;
}