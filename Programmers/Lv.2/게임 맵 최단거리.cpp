// 게임 맵 최단거리
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
int map[101][101], used[101][101];
int dir[2][4] = { { 0, 0, -1, 1 }, { -1, 1, 0, 0, } }; // 좌우상하
typedef struct {
	int y, x;
	int cnt;
} node;

// function
int BFS();

// solve
int solution(vector<vector<int>> maps) {
	int answer = 0;

	// parsing
	N = maps.size();
	M = maps[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = maps[i][j];
		}
	}

	// func call
	int temp = 0;
	temp = BFS();

	// result update
	answer = temp;

	// return result !
	return answer;
}

// Breadth-First Search
int BFS() {
	queue<node> que;
	que.push({ 0, 0, 1 });
	used[0][0] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];
			int nc = now.cnt + 1;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) { continue; }
			if (map[ny][nx] == 0) { continue; }
			if (used[ny][nx] == 1) { continue; }

			if (ny == (N - 1) && nx == (M - 1)) { // found !
				return nc;
			}

			used[ny][nx] = 1;
			que.push({ ny, nx, nc });
		}
	}

	return -1; // not found
}