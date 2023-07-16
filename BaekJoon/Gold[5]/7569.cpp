// 토마토(3차원) (7569) Gold[5]
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
int M, N, H;
int zero_tomato;
int box[101][101][101];
int used[101][101][101];
int dir[3][6] = {
	{0, 0, 0, 0, -1, 1},
	{0, 0, -1, 1, 0, 0},
	{-1, 1, 0, 0, 0, 0}
};
typedef struct {
	int z, y, x;
}node;
queue<node> backup_que;

// Function
void input();
void solve();
queue<node> BFS(queue<node> backup_que);

// Main
int main(int argc, char** argv) {
	FastIO;

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> box[k][i][j];
				if (box[k][i][j] == 0) { // 안익은
					zero_tomato++;
				}
				else if (box[k][i][j] == 1) { // 익은
					backup_que.push({ k, i, j });
				}
			}
		}
	}
}

// solution
void solve() {
	int day = 0;

	// 안익은 토마토 없을 때
	if (zero_tomato == 0) {
		cout << "0\n";
		return;
	}

	// Call by Function
	while (!backup_que.empty()) {

		backup_que = BFS(backup_que);
		
		day++;
		int debug = 0;
	} day--;

	// 안익은 토마토 check !
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) { 
				if (box[k][i][j] == 0) { day = -1; }
			}
		}
	}

	// Print result !
	cout << day << "\n";
}

// Breadth-First Search
queue<node> BFS(queue<node> backup_que) {
	queue<node> current_que;
	
	while (!backup_que.empty()) {
		node now = backup_que.front();
		backup_que.pop();

		used[now.z][now.y][now.x] = 1;

		for (int i = 0; i < 6; i++) {
			int nz = now.z + dir[0][i];
			int ny = now.y + dir[1][i];
			int nx = now.x + dir[2][i];

			if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (box[nz][ny][nx] == -1 || box[nz][ny][nx] == 1) { continue; }
			if (used[nz][ny][nx] == 1) { continue; }

			used[nz][ny][nx] = 1;
			box[nz][ny][nx] = 1;

			current_que.push({ nz, ny, nx });
		}
	}

	return current_que;
}