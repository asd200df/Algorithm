// 영역 구하기 (2583) Silver[1]
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
int N, M, K; // <= 100
int maps[105][105], used[105][105];
int dir[2][4] = { {-1, 0, 1, 0}, {0, -1, 0, 1} };
typedef struct { int y, x; }node;
vector<int> vec; // rectangle

// Function
void input();
void solve();
void BFS(int insy, int insx);

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
	cin >> N >> M >> K;

	int i1, i2, i3, i4;
	for (int i = 0; i < K; i++) {
		cin >> i1 >> i2 >> i3 >> i4;

		// rectangle setting ...
		i3--;
		i4--;

		for (int i = i2; i <= i4; i++) { // y축
			for (int j = i1; j <= i3; j++) { // x축
				maps[i][j] = 1;
			}
		}
	}

	int check = 0;
}

// solution
void solve() {
	int cnt = 0;
	
	// searching ...
	for (int i = 0; i < N; i++) {

		if (i == 4) {
			int debug2 = 0;
		}

		for (int j = 0; j < M; j++) {

			int debug = 0;

			if (maps[i][j] == 1) { continue; }
			if (used[i][j] == 1) { continue; }

			BFS(i, j);

			debug = 2;

			cnt++;
		}
	} 

	// sort
	if (!vec.empty()) { sort(vec.begin(), vec.end()); }

	// print result !
	if (cnt == 0) { cout << "0\n0\n"; }
	else {
		cout << cnt << "\n";
		for (int i = 0; i < vec.size(); i++) { cout << vec[i] << " "; }
	} cout << "\n";
}

// Breadth-First Search
void BFS(int insy, int insx) {
	int c = 1;
	queue<node> que;
	que.push({ insy, insx });
	used[insy][insx] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (used[ny][nx] == 1) { continue; }
			if (maps[ny][nx] == 1) { continue; }

			used[ny][nx] = 1;
			c++;

			que.push({ ny, nx });
		}
	}

	vec.push_back(c);
}