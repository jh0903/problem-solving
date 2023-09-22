#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int N, M, ans;
vector<int> num;

int main(void) {
	ios::ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	int pivot = 0;
	for (int x, i = 0;i < N;i++) {
		cin >> x;
		if (x < 0) pivot++;
		num.push_back(x);
	}
	sort(num.begin(), num.end());
	for (int i = 0;i < pivot;i += M) {
		ans += abs(num[i]) * 2;
	}
	for (int i = N - 1;i >= pivot;i -= M) {
		ans += abs(num[i]) * 2;
	}
	ans -= max(abs(num[0]), abs(num[N - 1]));
	cout << ans;
	return 0;
}