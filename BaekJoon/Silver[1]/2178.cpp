// ¹Ì·Î Å½»ö (2178) Silver[1]
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
int N, M; // <= 100
int map[101][101];
int used[101][101];
int dir[2][4] = { {0, 0, -1, 1}, {1, -1, 0, 0} };
typedef struct {
	int y, x, cost;
}node;
vector<node> vec;

// Function
void input();
void solve();
int BFS(node target);

// Main
int main(int argc, char** argv) {
	FastIO;

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N >> M;
	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			if (temp == '1') {
				map[i][j] = 1;
				vec.push_back({ i, j, 0 });
			}
		}
	}
}

// solution
void solve() {
	int cnt = 0;

	cnt = BFS({ 0, 0, 1 });

	cout << cnt << "\n";
}

// Breadth-First Search
int BFS(node target) {
	queue<node> que;
	que.push(target);

	used[target.y][target.x] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			int cost = now.cost + 1;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (used[ny][nx] == 1) { continue; }
			if (map[ny][nx] == 0) { continue; }

			if (ny == N - 1 && nx == M - 1) {
				return cost;
			}

			used[ny][nx] = 1;

			que.push({ ny, nx, cost });
		}
	}

	return -1;
}