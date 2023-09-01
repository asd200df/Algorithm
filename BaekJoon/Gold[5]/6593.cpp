// »ó¹ü ºôµù (6593) Gold[5]
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
bool flag = false;
int L, R, C; // <= 30
char building[35][35][35];
int dir[3][6] = { // µ¿, ¼­, ³², ºÏ, »ó, ÇÏ
	{ 0, 0, 0, 0, -1, 1 },
	{ 0, 0, 1, -1, 0, 0 },
	{ 1, -1, 0, 0, 0, 0, }
};
typedef struct { int z, y, x; }node;
node start;

// Function
void init();
void input();
void solve();
int BFS();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		input();
		if (flag) { break; }
		solve();
		init();
	}

	return 0;
}

// initialization
void init() {
	flag = false;
	// char building[35][35][35];
}

// input
void input() {
	cin >> L >> R >> C;

	if (L == 0 && R == 0 && C == 0) { flag = true; }
	else {
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int l = 0; l < C; l++) {
					cin >> building[i][j][l];
					if (building[i][j][l] == 'S') {
						start.z = i;
						start.y = j;
						start.x = l;
					}
				}
			}
		}
	}
}

// solution
void solve() {
	int BFS_Return_Value = 0;

	BFS_Return_Value = BFS();

	if (BFS_Return_Value == -21e8) { cout << "Trapped!\n"; }
	else { cout << "Escaped in " << BFS_Return_Value << " minute(s).\n"; }
}

// Breadth-First Search
int BFS() {
	int used[35][35][35] = { 0 };
	typedef struct { int z, y, x, c; }node2;
	queue<node2> que;
	que.push({ start.z, start.y, start.x, 0 });
	used[start.z][start.y][start.x] = 1;

	while (!que.empty()) {
		node2 now = que.front();
		que.pop();

		for (int i = 0; i < 6; i++) {
			int nz = now.z + dir[0][i];
			int ny = now.y + dir[1][i];
			int nx = now.x + dir[2][i];
			int nc = now.c + 1;

			if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C) { continue; }
			if (building[nz][ny][nx] == '#') { continue; }
			if (used[nz][ny][nx] == 1) { continue; }

			if (building[nz][ny][nx] == 'E') { // Escape !
				return nc;
			}

			used[nz][ny][nx] = 1;
			
			que.push({ nz, ny, nx, nc });
		}
	}

	return -21e8;
}