#include<iostream>
#include<queue>
using namespace std;

int N, M, ans;
int arr[2005][2005];
bool vis[2005][2005][5];
queue<pair<pair<int, int>, int>> q;
int dx[5] = { 0,  -1, 0, 1, 0 }; //상, 좌, 하, 우
int dy[5] = { 0,  0, -1, 0, 1 };

int cal_dir(int dir, int cur_dir) {
	if (dir == 1) {
		if (cur_dir == 2) return -1;
		if (cur_dir == 4) return -1;
		return cur_dir;
	}
	if (dir == 2) {
		if (cur_dir == 1) return -1;
		if (cur_dir == 3) return -1;
		return cur_dir;
	}
	if (dir == 3) {
		if (cur_dir == 1) return 4;
		if (cur_dir == 2) return 3;
		if (cur_dir == 3) return 2;
		if (cur_dir == 4) return 1;
	}
	if (dir == 4) {
		if (cur_dir == 1) return 2;
		if (cur_dir == 2) return 1;
		if (cur_dir == 3) return 4;
		if (cur_dir == 4) return 3;
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				for (int k = 1;k <= 4;k++) {
					q.push({ {i, j}, k }); //위치, 방향
					vis[i][j][k] = 1;
				}

			}
		}
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front().first;
		int dir = q.front().second; q.pop();
		int cur_dir;
		if (arr[cur.first][cur.second] == 9 || !arr[cur.first][cur.second]) cur_dir = dir;
		else cur_dir = cal_dir(arr[cur.first][cur.second], dir);
		if (cur_dir == -1) continue;
		int nx = cur.first + dx[cur_dir];
		int ny = cur.second + dy[cur_dir];
		if (arr[nx][ny] == 9)
			continue;
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || vis[nx][ny][cur_dir]) continue;
		q.push({ {nx, ny}, cur_dir });
		vis[nx][ny][cur_dir] = 1;
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			for (int k = 1;k <= 4;k++) {
				if (vis[i][j][k]) {
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}