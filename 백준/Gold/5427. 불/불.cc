#include<iostream>
#include<queue>
#include<algorithm>
#include <memory.h>
using namespace std;

int T;
char arr[1005][1005];
int fv[1004][1004], sv[1004][1004];
int sx, sy;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		int w, h, ans = 987654321;
		memset(sv, 0, sizeof(sv));
		cin >> w >> h;for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				fv[i][j] = 987654321;
			}
		}
		queue<pair<int, int>> sq, fq;
		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') {
					sx = i, sy = j;
					sq.push({ i,j });
					sv[i][j] = 1;
				}
				if (arr[i][j] == '*') {
					fq.push({ i,j });
					fv[i][j] = 1;
				}
			}
		}
		//불 먼저 이동
		while (!fq.empty()) {
			pair<int, int> cur = fq.front(); fq.pop();
			for (int i = 0;i < 4;i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (fv[nx][ny]!=987654321 || arr[nx][ny] == '#') continue;
				fq.push({ nx,ny });
				fv[nx][ny] = fv[cur.first][cur.second] + 1;
			}
		}
		
		while (!sq.empty()) {
			pair<int, int> cur = sq.front(); sq.pop();
			if (cur.first == 0 || cur.first == h - 1 || cur.second == 0 || cur.second == w - 1) {
				ans = min(ans, sv[cur.first][cur.second]);
				continue;
			}
			for (int i = 0;i < 4;i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (sv[nx][ny] || arr[nx][ny] == '#' || fv[nx][ny]<= (sv[cur.first][cur.second] + 1)) continue;
				sq.push({ nx,ny });
				sv[nx][ny] = sv[cur.first][cur.second] + 1;
			}
		}
		if (ans == 987654321) cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';
	}

	return 0;
}