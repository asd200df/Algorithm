// 적록색약 (10026) Gold[5]
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
int N; // <= 100
char maps[101][101];
bool used[2][101][101];
int dir[2][4] = { { -1, 0, 1, 0 }, { 0, -1, 0, 1 } };
typedef struct { int y, x; }node;

// Function
void input();
void solve();
void BFS(int type, node ins);

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
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
		}
	}
}

// solution
void solve() {
	int normal = 0;
	int anomaly = 0;

	// check
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (used[0][i][j] == false) { // 일반
				BFS(0, { i, j });
				normal++;
			}
			if (used[1][i][j] == false) { // 적록색약
				BFS(1, { i, j });
				anomaly++;
			}
		}
	}

	// result !
	cout << normal << " " << anomaly << "\n";
}

// Breadth-First Search
void BFS(int type, node ins) {
	queue<node> que;
	que.push(ins);
	used[type][ins.y][ins.x] = true;

	char color = maps[ins.y][ins.x];

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
			if (used[type][ny][nx]) { continue; }

			char ncolor = maps[ny][nx];
			if (type == 0) { // 일반
				if (color != ncolor) { continue; }
			}
			else if (type == 1) { // 적록색약
				if (color != 'B') {	if (ncolor == 'B') { continue; } }
				else { if (color != ncolor) { continue; } }
			}

			used[type][ny][nx] = true;

			que.push({ ny, nx });
		}
	}
}