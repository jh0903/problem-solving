#include<iostream>
#include<queue>
#include<algorithm>
#include <memory.h>
#include<vector>
using namespace std;

int N, M, s, e, ans;
vector<pair<int, int>> adj[100005];
bool vis[100005];

bool bfs(int mid) {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == e) return true;
		for (pair<int,int> nxt : adj[cur]) {
			if (vis[nxt.first] || nxt.second < mid) continue;
			q.push({ nxt.first });
			vis[nxt.first] = 1;
		}
	}
	return false;
}

int main(void) {
	ios::ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M >> s >> e;
	for (int i = 0;i < M;i++) {
		int h1, h2, k;
		cin >> h1 >> h2 >> k;
		adj[h1].push_back({ h2, k });
		adj[h2].push_back({ h1, k });
	}
	int le = 0, ri = 1000000;
	while (le <= ri) {
		int mid = (le + ri) / 2;
		if (bfs(mid)) {
			le = mid + 1;
			ans = max(ans, mid);
		}
		else {
			ri = mid - 1;
		}
	}
	cout << ans;

	return 0;
}