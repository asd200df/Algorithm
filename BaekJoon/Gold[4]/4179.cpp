// 불! (4179) Gold[4]
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
int N, M, ret; // <= 1,000
char maps[1005][1005], used[1005][1005], used2[1005][1005];
int dir[2][4] = { {-1, 0, 1, 0}, {0, -1, 0, 1} };
typedef struct{ int y, x; }node;
typedef struct{ int y, x, c; }node2;
queue<node> Fque;
queue<node2> Jque;

// Function
void input();
void solve();
void BFS(queue<node2> q);
void BFS2(queue<node> q);

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

			if (maps[i][j] == 'J') { Jque.push({ i, j, 0 }); }
			if (maps[i][j] == 'F') { Fque.push({ i, j }); }
		}
	}
}

// solution
void solve() {

	while (!Jque.empty()) {
	
		// J BFS call
		BFS(Jque);

		// end condition
		if (ret != 0) { break; }
		
		// F BFS call
		BFS2(Fque);
	}

	// print result !
	if (ret != 0) { cout << ret << "\n"; }
	else { cout << "IMPOSSIBLE\n"; }
}

// Breadth-First Search (J)
void BFS(queue<node2> q) {

	while (!Jque.empty()) { Jque.pop(); }
	
	while (!q.empty()) {
		node2 now = q.front();
		q.pop();

		used[now.y][now.x] = 1;

		// 불 위치 일 때
		if (maps[now.y][now.x] == 'F') { continue; }

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			int nc = now.c + 1;

			// 탈출 성공
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
				ret = nc;
				return;
			}
			
			if (maps[ny][nx] == 'F') { continue; }
			if (maps[ny][nx] == '#') { continue; }
			if (used[ny][nx] == 1) { continue; }

			used[ny][nx] = 1;

			Jque.push({ ny, nx, nc });
		}
	}
}

// Breadth-First Search (F)
void BFS2(queue<node> q) {

	while (!Fque.empty()) { Fque.pop(); }

	while (!q.empty()) {
		node now = q.front();
		q.pop();

		used2[now.y][now.x] = 1;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (used2[ny][nx] == 1) { continue; }
			if (maps[ny][nx] == '#') { continue; }

			used2[ny][nx] = 1;
			maps[ny][nx] = 'F';

			Fque.push({ ny, nx });
		}
	}
}