// 로봇 청소기 (14503) Gold[5]
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
int N, M; // <= 50
int cnt;
int start_y, start_x, start_d;
int maps[55][55];
int dir[2][4] = { {-1, 0, 1, 0}, {0, 1, 0, -1} }; // 0 북, 1 동, 2 남, 3 서

// Function
void input();
void solve();
void clean(int ny, int nx);
int navi(int ny, int nx);

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

	cin >> start_y >> start_x >> start_d;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}
}

// solution
void solve() {

	// now (x, y, direct)
	int ny = start_y;
	int nx = start_x;
	int nd = start_d;

	// simulation
	while (true) {
		int debug = 0;

		// 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다
		if (maps[ny][nx] == 0) { clean(ny, nx); }

		debug = 1;

		// 현재 칸의 주변 4칸 searching ...
		int chk = navi(ny, nx);

		// 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
		if (chk == 0) {
			int ntd = (nd + 2) % 4; // 바라보는 방향의 반대 방향

			int nty = ny + dir[0][ntd];
			int ntx = nx + dir[1][ntd];

			// 2-1 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로
			if (maps[nty][ntx] != 1) {
				ny = nty;
				nx = ntx;
				continue;
			}

			// 고려 사항 1 (범위를 넘어서는 경우)
			// if (nty < 0 || nty >= N || ntx < 0 || ntx >= M) { continue; }

			// 2-2 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동 멈춤
			if (maps[nty][ntx] == 1) { break; }
		}

		// 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
		else { // chk != 0 

			// 3-1 반시계 방향으로 90° 회전한다
			nd = nd - 1;
			if (nd == -1) { nd = 3; }

			// 3-2 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈칸인 경우 한 칸 전진한다
			int nty = ny + dir[0][nd];
			int ntx = nx + dir[1][nd];
			if (maps[nty][ntx] == 0) {
				ny = nty;
				nx = ntx;
			}

			// 3-3 1번으로 돌아간다
			continue;
		}

	}

	// print result !
	cout << cnt << "\n";
}

// cleaning
void clean(int ny, int nx) { 
	maps[ny][nx] = 9; 
	cnt++;
}

// Navigation
int navi(int ny, int nx) {
	int c = 0;

	for (int i = 0; i < 4; i++) {
		int nty = ny + dir[0][i];
		int ntx = nx + dir[1][i];

		if (nty < 0 || nty >= N || ntx < 0 || ntx >= M) { continue; }

		if (maps[nty][ntx] == 0) { c++; }
	}

	return c;
}