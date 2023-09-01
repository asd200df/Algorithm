// º¸¹°¼¶ (2589) Gold[5]
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N, M; // <= 50
char maps[55][55];
int dir[2][4] = { { -1, 0, 1, 0 }, { 0, -1, 0, 1 } };
typedef struct { int y, x, c; }node;
vector<node> vec;

// Function
void input();
void solve();
int BFS(node ins);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 'L') { vec.push_back({ i, j, 0 }); }
		}
	}
}

// solution
void solve() {
	int maxi = -21e8;

	for (int i = 0; i < vec.size(); i++) {
		int bfs_ret = 0;
		bfs_ret = BFS(vec[i]);
		if (maxi < bfs_ret) { maxi = bfs_ret; }
	}

	if (maxi == -21e8) { maxi = 0; }

	cout << maxi << "\n";
}

// Breadth-First Search
int BFS(node ins) {
	int ret = 0;
	int used[55][55] = { 0 };
	queue<node> que;
	que.push(ins);
	used[ins.y][ins.x] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			int nc = now.c + 1;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (maps[ny][nx] == 'W') { continue; }
			if (used[ny][nx] == 1) { continue; }

			if (ret < nc) { ret = nc; }

			used[ny][nx] = 1;

			que.push({ ny, nx, nc });
		}
	}

	return ret;
}