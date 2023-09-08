#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;

int V, E, P;
vector<pair<int, int>> adj[5005];

int dij(int s, int e) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	int dist[5005];
	for (int i = 1;i <= V;i++) dist[i] = 987654321;
	dist[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cur_v = pq.top().second;
		int cur_dist = pq.top().first; pq.pop();
		if (dist[cur_v] != cur_dist) continue;
		for (pair<int, int> nxt : adj[cur_v]) {
			if (dist[nxt.first] > dist[cur_v] + nxt.second) {
				dist[nxt.first] = dist[cur_v] + nxt.second;
				pq.push({ dist[nxt.first], nxt.first });
			}
		}
	}
	return dist[e];
}

int main(void) {
	ios::ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> V >> E >> P;
	for (int i = 0;i < E;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	int a = dij(1, P);
	int b = dij(P, V);
	int c = dij(1, V);
	if (a + b <= c) cout << "SAVE HIM";
	else cout << "GOOD BYE";

	return 0;
}