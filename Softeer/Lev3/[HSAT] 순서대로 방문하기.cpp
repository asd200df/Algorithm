// 순서대로 방문하기 [HSAT 7회 정기 코딩 인증평가 기출]
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Global
int N, M; // N <= 4, M <= N^2
int cnt, end_y, end_x;
int maps[10][10], used[10][10];
int dir[2][4] = { { -1, 0, 1, 0 }, { 0, -1, 0, 1 } };
typedef struct { int y, x; }node;
vector<node> vec;

// Function
void input();
void solve();
void DFS(node now, int target);

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

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 1) { maps[i][j] = -1; }
		}
	}

	int inp1, inp2;
	for (int i = 1; i <= M; i++) {
		cin >> inp1 >> inp2;
		maps[inp1][inp2] = i;
		vec.push_back({ inp1, inp2 });
	}
}

// solution
void solve() {

	/* debug
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout << maps[i][j] << " ";
		} cout << "\n";
	} */

	int start_y = vec[0].y;
	int start_x = vec[0].x;
	end_y = vec[vec.size() - 1].y;
	end_x = vec[vec.size() - 1].x;

	used[start_y][start_x] = 1;
	DFS({ start_y, start_x }, 2);

	cout << cnt << "\n";
}

// Depth-First Search
void DFS(node now, int target) {
	if (now.y == end_y && now.x == end_x) {
		if (maps[now.y][now.x] == target - 1) { cnt++; }

		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = now.y + dir[0][i];
		int nx = now.x + dir[1][i];

		if (ny < 1 || ny > N || nx < 1 || nx > N) { continue; }
		if (maps[ny][nx] == -1) { continue; }
		if (used[ny][nx] == 1) { continue; }

		if (maps[ny][nx] != 0) {
			if (maps[ny][nx] == target) {
				used[ny][nx] = 1;
				DFS({ ny, nx }, target + 1);
				used[ny][nx] = 0;
			}
			else { continue; }
		}
		else {
			used[ny][nx] = 1;
			DFS({ ny, nx }, target);
			used[ny][nx] = 0;
		}
	}
}