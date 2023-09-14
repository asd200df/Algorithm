// บา (5427) Gold[4]
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
int T, W, H; // W,h <= 1,000
int mini = 21e8;
char maps[1001][1001];
bool used[3][1001][1001];
int dijkstra[1001][1001];
int dir[2][4] = { { -1, 0, 1, 0 }, { 0, -1, 0, 1 } };
typedef struct { int y, x; }node;
queue<node> Hque, Fque, blank;

// Function
void init();
void input();
void solve();
bool BFS(int type);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		init();
		input();
		solve();
	}

	return 0;
}

// initialization
void init() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dijkstra[i][j] = 21e8;
		}
	}
	mini = 21e8;
	for (int i = 1; i <= 2; i++) {
		for (int j = 0; j < 1001; j++) {
			for (int l = 0; l < 1001; l++) {
				used[i][j][l] = false;
			}
		}
	}
	Hque = blank;
	Fque = blank;
}

// input
void input() {
	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == '@') { 
				Hque.push({ i, j }); 
				dijkstra[i][j] = 0;
			}
			else if (maps[i][j] == '*') { Fque.push({ i, j }); }
		}
	}
}

// solution
void solve() {
	bool flag = false;

	// Searching ..
	while (!Hque.empty()) {
		for (int type = 2; type >= 1; type--) {
			if(BFS(type)) { flag = true; }
			// int debug = 0;
		}
		if (flag) { break; }
	}

	// result !
	if (flag) { cout << mini << "\n"; }
	else { cout << "IMPOSSIBLE\n"; }
}

// Breadth-First Search
bool BFS(int type) {
	queue<node> que;
	if (type == 1) { 
		que = Hque;
		Hque = blank;
	}
	else { 
		que = Fque; 
		Fque = blank;
	}

	while (!que.empty()) {
		node now = que.front();
		que.pop();
		used[type][now.y][now.x] = true;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			int nc = dijkstra[now.y][now.x] + 1;

			if (type == 1 && (ny < 0 || ny >= H || nx < 0 || nx >= W)) { 
				mini = nc;
				return true; 
			}
			else if (type == 2 && (ny < 0 || ny >= H || nx < 0 || nx >= W)) { continue; }
			if (maps[ny][nx] == '#') { continue; }
			if (used[type][ny][nx]) { continue; }
			if (type == 1) {
				if (maps[ny][nx] == '*' || dijkstra[ny][nx] < nc) {
					continue;
				}
			}
			if (type == 2) { maps[ny][nx] = '*'; }

			used[type][ny][nx] = true;

			if (type == 1) { 
				dijkstra[ny][nx] = nc;
				Hque.push({ ny, nx }); 
			}
			else { Fque.push({ ny, nx }); }
		}
	}

	return false;
}