// 나이트의 이동 (7562) Silver[1]
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

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int T, N; // N <= 300
int map[301][301];
int used[301][301];
int result = 0;
int dir[2][8] = {
	{-1, -1, -2, -2, 1, 1, 2, 2},
	{-2, 2, -1, 1, -2, 2, -1, 1}
};
typedef struct {
	int y, x, mv;
}node;
node start;
node target;

// Function
void init();
void input();
void solve();
void BFS();

// Main
int main(int argc, char** argv) {
	FastIO;

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		input();
		solve();
	}

	return 0;
}

// initialization
void init() {
	N = 0;
	for (int i = 0; i < 301; i++) {
		memset(map[i], 0, sizeof(map[i]));
		memset(used[i], 0, sizeof(used[i]));
	}
	result = 0;
	node start = target = { 0, 0, 0 };
}

// input
void input() {
	cin >> N;
	
	int iy, ix;

	cin >> iy >> ix;
	start = { iy, ix, 0 };

	cin >> iy >> ix;
	target = { iy, ix, 0 };
}

// solution
void solve() {

	if (!(start.y == target.y && start.x == target.x)) { BFS(); }

	cout << result << "\n";
}

// Breadth-First Search
void BFS() {
	queue<node> que;
	que.push(start);

	used[start.y][start.x] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 8; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			int nmv = now.mv + 1;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
			if (used[ny][nx] == 1) { continue; }

			if (ny == target.y && nx == target.x) {
				result = nmv;
				return;
			}

			used[ny][nx] = 1;

			que.push({ ny, nx, nmv });
		}
	}
}