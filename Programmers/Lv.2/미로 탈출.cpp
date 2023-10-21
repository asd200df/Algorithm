// πÃ∑Œ ≈ª√‚
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

// global
int N, M;
char mapi[101][101];
int dir[2][4] = { { -1, 0, 1, 0 }, { 0, -1, 0, 1 } };
typedef struct { int y, x; }node;

// function
int BFS(node st, node ed);

// solve
int solution(vector<string> maps) {
	int answer = 0;

	// Local
	int first = -1, second = -1;
	bool flag1 = true, flag2 = true;
	node st, ed, le;

	// initialization
	N = maps.size();
	M = maps[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			mapi[i][j] = maps[i][j];
			if (maps[i][j] == 'S') {
				st.y = i;
				st.x = j;
			}
			else if (maps[i][j] == 'L') {
				le.y = i;
				le.x = j;
			}
			else if (maps[i][j] == 'E') {
				ed.y = i;
				ed.x = j;
			}
		}
	}

	// Start >> Lever
	first = BFS(st, le);
	if (first == -1) { flag1 = false; }

	// Lever >> End
	if (flag1) { second = BFS(le, ed); }
	if (second == -1) { flag2 = false; }

	// debug
	// cout << first << "\n";
	// cout << second << "\n";

	// Update
	if (flag1 && flag2) { answer = first + second; }
	else { answer = -1; }

	// return result !
	return answer;
}

// Breadth-First Search
typedef struct { int y, x, c; }node2;
int BFS(node st, node ed) {
	bool used[101][101] = { false };
	queue<node2> que;
	que.push({ st.y, st.x, 0 });
	used[st.y][st.x] = true;

	while (!que.empty()) {
		node2 now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			int nc = now.c + 1;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (mapi[ny][nx] == 'X') { continue; }
			if (used[ny][nx]) { continue; }

			if (ny == ed.y && nx == ed.x) { return nc; }

			used[ny][nx] = true;
			que.push({ ny, nx, nc });
		}
	}

	return -1;
}