// 연구소 (14502) Gold[4]
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
int N, M; // <= 8
int total;
int maps[10][10];
int mini = 21e8;
bool used[70];
int dir[2][4] = { { -1, 0, 1, 0 }, { 0, -1, 0, 1 } };
typedef struct { int y, x; }node;
vector<node> blank;
queue<node> virous;

// Function
void input();
void solve();
void DFS(int now, int start_point);
int BFS();

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

	total = N * M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 2) { 
				virous.push({ i, j }); 
				// total--;
			}
			else if (maps[i][j] == 0) { blank.push_back({ i, j }); }
			else { // maps[i][j] == 1
				total--;
			}
		}
	}
}

// solution
void solve() {
	total -= 3; // 벽 3개 빼야지 

	DFS(0, 0);

	cout << total - mini << "\n";
}

// Depth-First Search
void DFS(int now, int start_point) {
	if (now == 3) {
		int temp;
		temp = BFS();
		mini = min(mini, temp);
		return;
	}

	for (int i = start_point; i < blank.size(); i++) {
		node nn = blank[i];

		if (used[i]) { continue; }

		maps[nn.y][nn.x] = 1;
		used[i] = true;
		DFS(now + 1, i);
		used[i] = false;
		maps[nn.y][nn.x] = 0;
	}
}

// Breadth-First Search
int BFS() {
	int cnt = 0;
	// int debug[10][10] = { 0 };
	bool visit[10][10] = { false };
	queue<node> que;
	que = virous;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		visit[now.y][now.x] = true;
		cnt++;
		// debug[now.y][now.x] = cnt;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (maps[ny][nx] == 1) { continue; }
			if (maps[ny][nx] == 2) { continue; }
			if (visit[ny][nx]) { continue; }

			visit[ny][nx] = true;

			que.push({ ny, nx });
		}
	}

//	if (maps[0][1] == 1 && maps[1][0] == 1 && maps[3][5] == 1) {
//		int debug2 = 0;
//	}

	return cnt;
}