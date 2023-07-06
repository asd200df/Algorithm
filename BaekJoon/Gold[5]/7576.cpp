// ≈‰∏∂≈‰ (7576) Gold[5]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N, M, zero_total, zero_cnt;
int box[1001][1001], used[1001][1001];
int dir[2][4] = { { 0, 0, -1, 1 }, { 1, -1, 0, 0 } };
typedef struct {
	int y, x;
}node;
queue<node> que;

// Function
void input();
void solve();
queue<node> BFS();

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
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 0) { zero_total++; }
			if (box[i][j] == 1) { que.push({ i, j }); }
		}
	}
}

// solution
void solve() {
	int cnt = 0;

	while (!que.empty()) {
		que = BFS();
		cnt++;
	} cnt--;

	if (zero_total == zero_cnt) { cout << cnt << "\n"; }
	else { cout << "-1\n"; }
}

// Flood Fill
queue<node> BFS() {
	queue<node> temp;

	while (!que.empty()) {
		node now = que.front();
		que.pop();
		used[now.y][now.x] = 1;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (used[ny][nx] == 1) { continue; }
			if (box[ny][nx] == 1 || box[ny][nx] == -1) { continue; }

			zero_cnt++;
			used[ny][nx] = 1;
			temp.push({ ny, nx });
		}
	}

	return temp;
}