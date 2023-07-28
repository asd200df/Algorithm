// 벽 부수고 이동하기 (2206) Gold[3]
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
int N, M; // <= 1,000
int map[1001][1001];
int used[1001][1001][2];
int dir[2][4] = { {0, 0, -1, 1}, {1, -1, 0, 0} };
typedef struct {
	int y, x, cnt, otc;
}node;

// Function
void input();
void solve();
int BFS();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	if (N == 1 && M == 1 && map[0][0] == 0) { cout << "1\n"; }
	else { solve(); }

	return 0;
}

// input
void input() {
	cin >> N >> M;

	char inp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> inp;
			map[i][j] = inp - '0';
		}
	}
	// int debug = 0;
}

// solution
void solve() {
	int result = 0;

	result = BFS();

	cout << result << "\n";

}

// Breadth-First Search
int BFS() {
	queue<node> que;
	que.push({ 0, 0, 1, 0 });
	used[0][0][0] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		// 4 direct Searching
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			int nc = now.cnt + 1;
			int notc = now.otc;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (used[ny][nx][notc] >= 1) { continue; }

			// 목적지 도착
			if (ny == (N - 1) && nx == (M - 1)) {
				return nc;
			}

			if (map[ny][nx] == 1) { // 벽 만남
				if (notc == 0) { // 기회 있을 때
					used[now.y][now.x][1] = 1;
					used[ny][nx][1] = 1;
					que.push({ ny, nx, nc, 1 });
					continue;
				}
				else { // 기회 없을 때 
					continue;
				}
			}

			used[ny][nx][notc] = 1;
			que.push({ ny, nx, nc, notc });
		}
	}

	return -1;
}