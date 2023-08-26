// 알파벳 (1987) Gold[4]
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
int R, C; // <= 20
int maxi = -21e8;
char maps[25][25];
int dir[2][4] = { {-1, 0, 1, 0}, {0, -1, 0, 1} };
typedef struct { int y, x; }node;
bool alpha[30];

// Function
void input();
void solve();
void DFS(node now, int cnt);

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
		}
	}
}

// solution
void solve() {

	// DFS func call
	alpha[maps[0][0] - 65] = true;
	DFS({0, 0}, 1);

	// print result !
	if (maxi == 0) { cout << "1\n"; }
	else { cout << maxi << "\n"; } 
}

// Depth-First Search
void DFS(node now, int cnt) {
	// if(종료 조건) { return; }

	maxi = max(maxi, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = now.y + dir[0][i];
		int nx = now.x + dir[1][i];
		int nal = maps[ny][nx] - 65;

		if (ny < 0 || ny >= R || nx < 0 || nx >= C) { continue; }
		if (alpha[nal] == true) { continue; }

		alpha[nal] = true;
		DFS({ ny, nx }, cnt + 1);
		alpha[nal] = false;
	}
}
