// 안전 영역 (2468) Silver[1]
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
int cnt_maxi = -21e8;
int maps[105][105], used[105][105];
int dir[2][4] = { {0, 0, -1, 1}, {-1, 1, 0, 0} };
typedef struct {
	int y, x;
}node;

// Function
void input();
void solve();
void BFS(int type, int lim, int insy, int insx);

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

	int inp, temp[101];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
		}
	}
}

// solution
void solve() {
	int result = 0;

	// searching
	int cnt, ny, nx;
	for (int i = 0; i < 101; i++) {
		int target = i;
		cnt = 0;

		if (target == 4) {
			int debug = 0;
		}

		// water 
		for (int l = 0; l < N; l++) {
			for (int k = 0; k < N; k++) {

				if (used[l][k] == 1) { continue; }
				if (maps[l][k] > target) { continue; }

				BFS(1, 0, l, k);
			}
		}

		int debug2 = 0;

		// area
		for (int l = 0; l < N; l++) {
			for (int k = 0; k < N; k++) {

				if (used[l][k] == 1) { continue; }

				BFS(2, 0, l, k);

				cnt++;
			}
		}

		// maximum update
		cnt_maxi = max(cnt_maxi, cnt);

		// init used
		for (int l = 0; l < N; l++) {
			memset(used[l], 0, sizeof(used[l])); 
		}
	}

	// update
	if (cnt_maxi != -21e8) { result = cnt_maxi; }

	// print result !
	cout << result << "\n";
}

// Breadth-First Search
void BFS(int type, int lim, int insy, int insx) {
	queue<node> que;
	que.push({ insy, insx });
	used[insy][insx] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
			if (used[ny][nx] == 1) { continue; }
			if (type == 1) { if (maps[ny][nx] > lim) { continue; } }
			
			used[ny][nx] = 1;

			que.push({ ny, nx });
		}
	}
}