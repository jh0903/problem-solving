#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N;
long long ans;
vector<long long> pos, neg, ze;

int main(void) {
	ios::ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int x, i = 0;i < N;i++) {
		cin >> x;
		if (x > 0) pos.push_back(x);
		else if (x < 0) neg.push_back(x);
		else ze.push_back(x);
	}
	sort(pos.begin(), pos.end());
	for (int i = pos.size() - 1; i>=0; i--) {
		if (!i) {
			ans += pos[i];
			break;
		}
		if (pos[i] == 1 || pos[i-1] == 1) {
			ans += pos[i];
			continue;
		}
		ans += pos[i] * pos[i - 1]; i--;
	}
	sort(neg.begin(), neg.end());
	for (int i = 0;i < neg.size();i++) {
		if (i == neg.size() - 1) {
			if (ze.empty()) {
				ans += neg[i];
			}
			break;
		}
		ans += neg[i] * neg[i + 1]; i++;
	}
	cout << ans;

	return 0;
}