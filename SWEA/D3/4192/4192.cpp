// 수영대회 (완전 탐색)
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

int M, map[20][20], s1, s2, e1, e2, used[20][20];
typedef struct {
	int y, x, lev;
}str;
queue<str> que;
int directX[] = { 0, 0, 1, -1 };
int directY[] = { 1, -1, 0, 0 };

int BFS() {
	used[s1][s2] = 1;
	que.push({ s1, s2, 0 });

	while (!que.empty()) {
		str now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];

			if (ny < 0 || nx < 0 || ny >= M || nx >= M) continue;
			if (map[ny][nx] == 1) continue;
			if (used[ny][nx] == 1) continue;

			if (ny == e1 && nx == e2) return now.lev + 1;

			used[ny][nx] = 1;
			que.push({ ny, nx,  now.lev + 1 });

		}

	}
	return -1;
}

void init() {
	memset(map, 0, sizeof(map));
	memset(used, 0, sizeof(used));
	while (!que.empty()) {
		que.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();  // init func call
		
		cin >> M;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		cin >> s1 >> s2 >> e1 >> e2;

		int result = BFS();  // BFS func call

		cout << "#" << tc + 1 << " " << result << "\n";
	}

	return 0;
}