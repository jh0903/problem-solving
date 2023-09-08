#include<iostream>
#include<queue>
#include<algorithm>
#include <memory.h>
#include<vector>
using namespace std;

int N, K;
queue<int> q;

int main(void) {
	ios::ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> K;
	for (int i = 1;i <= N;i++) q.push(i);
	while (q.size() >= K) {
		int top = q.front(); q.pop();
		for (int i = 0;i < K - 1;i++) q.pop();
		q.push(top);
	}
	cout << q.front();

	return 0;
}