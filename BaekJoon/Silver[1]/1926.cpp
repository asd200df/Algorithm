// ±×¸² (1926) Silver[1]
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
int N, M; // <= 500
int maxi = -21e8;
int maps[505][505], used[505][505];
int dir[2][4] = { {-1, 0, 1, 0}, {0, -1, 0, 1} };
typedef struct { int y, x; }node;
vector<node> vec;

// Function
void input();
void solve();
void BFS(int nowY, int nowX);

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
			if (maps[i][j] == 1) { vec.push_back({ i, j }); }
		}
	}
}

// solution
void solve() {
	int cnt = 0;

	for (int i = 0; i < vec.size(); i++) {
		int ny = vec[i].y;
		int nx = vec[i].x;
		
		if (used[ny][nx] == 1) { continue; }

		BFS(ny, nx);
		cnt++;
	}

	if (maxi == -21e8) { maxi = 0; }

	cout << cnt << "\n";
	cout << maxi << "\n";
}

// Breadth-First Search
void BFS(int nowY, int nowX) {
	int c = 1;
	queue<node> que;
	que.push({ nowY, nowX });
	used[nowY][nowX] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (maps[ny][nx] == 0) { continue; }
			if (used[ny][nx] == 1) { continue; }

			used[ny][nx] = 1;

			c++;

			que.push({ ny, nx });
		}
	}

	maxi = max(maxi, c);
}