// ³ì»ö ¿Ê ÀÔÀº ¾Ö°¡ Á©´ÙÁö? (4485) Gold[4]
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
int N; // <= 125
int TC;
int maps[130][130];
int dijkstra[130][130];
typedef struct { int y, x; }node;
int dir[2][4] = { { -1, 0, 1, 0 }, { 0, -1, 0, 1 } };

// Function
void input();
void solve();
void BFS();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin	>> N;
		if (N == 0) { break; }
		TC++;
		input();
		solve();
	}

	return 0;
}

// input
void input() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
			dijkstra[i][j] = 21e8;
		}
	}

}

// solution
void solve() {

	// func call
	BFS();

	int deubg = 0;

	// print result !
	cout << "Problem " << TC << ": " << dijkstra[N - 1][N - 1] << "\n";
}

// Breadth-First Search
void BFS() {
	queue<node> que;
	que.push({ 0, 0 });
	dijkstra[0][0] = maps[0][0];

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		// if (now.x == (N - 1) && now.y == (N - 1)) { return; }

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			int nv = dijkstra[now.y][now.x] + maps[ny][nx];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
			if (dijkstra[ny][nx] <= nv) { continue; }

			dijkstra[ny][nx] = nv;
			que.push({ ny, nx });
		}
	}
}