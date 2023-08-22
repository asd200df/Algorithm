// 빙산 (2573) Gold[4]
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
int N, M; // <= 300
int iceberg;
int maps[305][305], used[305][305];
int dir[2][4] = { { -1, 1, 0, 0 }, { 0, 0, -1, 1 } };
typedef struct { int y, x; }node;
vector<node> vec;

// Function
void input();
void solve();
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
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
			if (maps[i][j] != 0) { 
				vec.push_back({ i, j });
				iceberg++; 
			}
		}
	}
}

// solution
void solve() {
	int year = 0;
	int debug = 0;

	int group;
	while (true) {

		// used init
		for (int i = 0; i < 305; i++) { memset(used[i], 0, sizeof(used[i])); }

		// ice melt
		int w;
		for (int i = 0; i < vec.size(); i++) {
			node now = vec[i];

			if (now.y == -1 && now.x == -1) { continue; }

			w = 0;
			for (int j = 0; j < 4; j++) {
				int ny = now.y + dir[0][j];
				int nx = now.x + dir[1][j];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
				if (maps[ny][nx] != 0) { continue; }

				w++;
			}

			if ((maps[now.y][now.x] - w) <= 0) { 
				maps[now.y][now.x] = -1; 
				iceberg--;
			}
			else { maps[now.y][now.x] -= w; }
		}

		// second set (얼음이 동시에 녹기에 아까 0으로 안바꾼 거 바꾸기)
		for (int i = 0; i < vec.size(); i++) {
			node now = vec[i];
			if (maps[now.y][now.x] == -1) { maps[now.y][now.x] = 0; }
			if (maps[now.y][now.x] == 0) { vec[i] = { -1, -1 }; }
		}

		// find iceberg group
		group = 0;
		for (int i = 0; i < vec.size(); i++) {
			node now = vec[i];

			if (now.y == -1 && now.x == -1) { continue; }
			if (used[now.y][now.x] == 1) { continue; }

			BFS(now);

			group++;
		}

		// time++
		year++;

		// end condition
		if (group >= 2) { break; }
		if (iceberg == 0) { 
			year = 0;
			break; 
		}
	}

	cout << year << "\n";
}

// Breadth-First Search
void BFS(node ins) {
	queue<node> que;
	que.push(ins);
	used[ins.y][ins.x] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (used[ny][nx] == 1) { continue; }
			if (maps[ny][nx] == 0) { continue; }

			used[ny][nx] = 1;

			que.push({ ny, nx });
		}
	}
}