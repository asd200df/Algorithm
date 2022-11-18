// 수영대회 결승전 (완전 탐색 + 구현)
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// global
int N, map[20][20], s1, s2, e1, e2;
int dijkstra[20][20]; // 이거 init() func 에서 21e8 으로 바꿔야 돼
int dirY[] = { 0, 0, -1, 1 };
int dirX[] = { 1, -1, 0, 0 };
typedef struct {
	int y, x;
}str;
queue<str> que;

int BFS() { // BFS func
	que.push({ s1, s2 });
	dijkstra[s1][s2] = 0;

	while (!que.empty()) {
		str now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dirY[i];
			int nx = now.x + dirX[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (map[ny][nx] == 1) continue;
			if (map[ny][nx] == 2) { // vortex
				// 보수 구하기
				int tmp = dijkstra[now.y][now.x] + (3 - (dijkstra[now.y][now.x] % 3));
				if (tmp < dijkstra[ny][nx]) {
					dijkstra[ny][nx] = tmp;
					que.push({ ny, nx });
				}
			}
			else {
				if (dijkstra[now.y][now.x] + 1 < dijkstra[ny][nx])
				{
					dijkstra[ny][nx] = dijkstra[now.y][now.x] + 1;
					que.push({ ny, nx });
				}
			}
		}
	}

	return dijkstra[e1][e2];
}

int solve() { // solution func
	if (BFS() != 21e8) return dijkstra[e1][e2];
	else return -1;
}

void input() { // input func
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> s1 >> s2;
	cin >> e1 >> e2;
}

void init() { // initialization func
	memset(map, 0, sizeof(map));
	for (int i = 0; i < 20; i++) { fill(&dijkstra[i][0], &dijkstra[i][20], 21e8); }
	while (!que.empty()) { que.pop(); }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	
	for (int tc = 0; tc < T; tc++) {
		init();
		input();

		int result = solve();
		cout << "#" << tc + 1 << " " << result << "\n";
	}

	return 0;
}
