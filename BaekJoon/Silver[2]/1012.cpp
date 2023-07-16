// ¿Ø±‚≥Û πË√ﬂ (1012) Silver[2]
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

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int T, M, N, K;
int map[55][55];
int used[55][55];
int dir[2][4] = { {0, 0, -1, 1}, {1, -1, 0, 0} };
typedef struct {
	int y, x;
}node;
vector<node> vec;

// Function
void init();
void input();
void solve();
void BFS(node target);

// Main
int main(int argc, char** argv) {
	FastIO;

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		input();
		solve();
	}

	return 0;
}

// initialization
void init() {
	M = N = K = 0;
	for (int i = 0; i < 55; i++) {
		memset(map[i], 0, sizeof(map[i]));
		memset(used[i], 0, sizeof(used[i]));
	}
	vec.clear();
}

// input
void input() {
	cin >> M >> N >> K;
	int inp_y, inp_x;
	for (int i = 0; i < K; i++) {
		cin >> inp_x >> inp_y;
		vec.push_back({ inp_y, inp_x });
		map[inp_y][inp_x] = 1;
	}
}

// solution
void solve() {
	int need = 0;

	for (int i = 0; i < vec.size(); i++) {
		node now = vec[i];
		
		if (used[now.y][now.x] == 1) { continue; }
		BFS(now);
		need++;
	}

	cout << need << "\n";
}

// Breadth-First Search && Flood Fill
void BFS(node target) {
	queue<node> que;
	que.push(target);

	used[target.y][target.x] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (used[ny][nx] == 1) { continue; }
			if (map[ny][nx] == 0) { continue; }

			used[ny][nx] = 1;

			que.push({ ny, nx });
		}
	}
}