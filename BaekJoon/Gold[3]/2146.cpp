// 다리 만들기 (2146) Gold[3]
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
int N;
int mini = 21e8;
int maps[103][103], used[103][103];
int dir[2][4] = { {-1, 0, 1, 0}, {0, -1, 0, 1} };
typedef struct { int y, x; }node;
vector<node> vec;

// Function
void input();
void solve();
void FF(node ins, int color);
void BFS(node ins);

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

	// 섬 테두리 담기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (maps[i][j] == 0) { continue; }

			for (int l = 0; l < 4; l++) {
				int ny = i + dir[0][l];
				int nx = j + dir[1][l];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }

				if (maps[ny][nx] == 0) { // 주위에 바다 발견
					vec.push_back({ i, j });
					break;
				}
			}
		}
	}

	// 섬 구분하기
	int cnt = 1;
	for (int i = 0; i < vec.size(); i++) {
		node n = vec[i];

		if (used[n.y][n.x] == 1) { continue; }
		FF(n, cnt);
		cnt++;
	}

	// 섬끼리의 거리 찾기 
	for (int i = 0; i < vec.size(); i++) {
		node n = vec[i];

		BFS(n);
	}

	// 결과 출력
	cout << mini << "\n";
}

// Flood Fill
void FF(node ins, int color) {
	queue<node> que;
	que.push(ins);
	used[ins.y][ins.x] = 1;
	maps[ins.y][ins.x] = color;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
			if (maps[ny][nx] == 0) { continue; }
			if (used[ny][nx] == 1) { continue; }

			used[ny][nx] = 1;
			maps[ny][nx] = color;

			que.push({ ny, nx });
		}
	}
}

// Breadth-First Search
void BFS(node ins) {
	int visit[103][103] = { 0 };
	typedef struct { int y, x, c; }node2;
	queue<node2> que;
	que.push({ ins.y, ins.x, 0 });
	visit[ins.y][ins.x] = 1;

	int ego = maps[ins.y][ins.x];

	while (!que.empty()) {
		node2 now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			int nc = now.c + 1;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
			if (visit[ny][nx] == 1) { continue; }
			if (maps[ny][nx] == ego) { continue; }
			else {
				if (maps[ny][nx] != 0) { 
					int debug = 0;
					mini = min(mini, now.c); 
					// return;
				}
			}

			visit[ny][nx] = 1;

			que.push({ ny, nx, nc });
		}
	}
}