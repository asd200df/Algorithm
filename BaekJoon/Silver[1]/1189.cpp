// ÄÄ¹éÈ¨ (1189) Silver[1]
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
int N, M, K; // N, M <= 5, K <= 25
int startY, startX, endY, endX;
int cnt;
char maps[10][10];
int used[10][10];
int dir[2][4] = { {0, 0, -1, 1}, {1, -1, 0, 0} };

// Function
void input();
void solve();
void DFS(int now, int y, int x);

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
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}
}

// solution
void solve() {

	// init
	startY = N - 1;
	startX = 0;
	endY = 0;
	endX = M - 1;

	// func call
	used[startY][startX] = 1;
	DFS(1, startY, startX);

	// Print result !
	cout << cnt << "\n";
}

// Depth-First Search
void DFS(int now, int y, int x) {
	if (now == K && y == endY && x == endX) {
		cnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[0][i];
		int nx = x + dir[1][i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
		if (maps[ny][nx] == 'T') { continue; }
		if (used[ny][nx] == 1) { continue; }

		used[ny][nx] = 1;
		DFS(now + 1, ny, nx);
		used[ny][nx] = 0;
	}
}