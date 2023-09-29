// ≈ª√‚ (3055) Gold[4]
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
int R, C; // <= 50
int dir[2][4] = { {-1, 0, 1, 0}, {0, -1, 0, 1} };
bool flag = false;
char maps[55][55];
bool used[2][55][55];
typedef struct { int y, x; }node;
node ed;
queue<node> dochi, water;

// Function
void input();
void solve();
void BFS(int type);

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
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maps[i][j];

			if (maps[i][j] == '*') { 
				water.push({ i, j }); 
				used[0][i][j] = true;
			}
			else if (maps[i][j] == 'S') { 
				dochi.push({ i, j });
				used[1][i][j] = true;
			}
			else if (maps[i][j] == 'D') {
				ed.y = i;
				ed.x = j;
			}
		}
	}
}

// solution
void solve() {
	int cnt = 0;

	while (!dochi.empty()) {

		cnt++;

		for (int i = 0; i < 2; i++) { BFS(i); }

		if (flag) { break; }
	}

	if (flag) { cout << cnt << "\n"; }
	else { cout << "KAKTUS\n"; }
}

// Breadth-First Search
void BFS(int type) {
	queue<node> temp, emp;
	if (type == 0) { 
		temp = water;
		water = emp;
	}
	else { // type == 1
		temp = dochi;
		dochi = emp;
	}

	while (!temp.empty()) {
		node now = temp.front();
		temp.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C) { continue; }
			if (used[type][ny][nx]) { continue; }
			if (maps[ny][nx] == 'X') { continue; }
			
			if (type == 0) { // water
				if (maps[ny][nx] == 'D') { continue; }

				used[type][ny][nx] = true;
				maps[ny][nx] = '*';
				water.push({ ny, nx });
			}
			else { // type == 1 // dochi
				if (maps[ny][nx] == '*') { continue; }

				if (maps[ny][nx] == 'D') {
					flag = true;
					return;
				}

				used[type][ny][nx] = true;
				dochi.push({ ny , nx });
			}
		}

	}

}