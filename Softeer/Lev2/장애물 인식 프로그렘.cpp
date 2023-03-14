// 장애물 인식 프로그램
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>
// #include<stdio.h>

// #define _CRT_SECURE_NO_WARNINGS

using namespace std;

// Global
int N, result2_idx;
int used[26][26] = { 0 };
char map[26][27];
int result1, result2[500];
int directY[] = { 0, 0, -1, 1 };
int directX[] = { -1, 1, 0, 0 };
typedef struct {
	int y;
	int x;
}str;

// Function
void input();
void solve();
void floodfill(int y, int x);

// MAIN
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	// sort (defalut = ascending)
	sort(result2, result2 + result2_idx);
	result1 = result2_idx;

	cout << result1 << "\n";
	for (int i = 0; i < result1; i++) {
		cout << result2[i] << "\n";
	}

	return 0;
}

// input
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
}

// solution
void solve() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == '0') continue;
			if (used[y][x] == 1) continue;
			floodfill(y, x);
		}
	}
}

// floodfill & BFS search
void floodfill(int y, int x) {
	queue<str> que;
	int tmp_cnt = 1; // 들어오는 y, x  자리에 1 카운트 하고 시작

	que.push({ y, x });
	used[y][x] = 1;

	// BFS search
	while (!que.empty()) {
		str now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + directY[i];
			int nx = now.x + directX[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (used[ny][nx] == 1) continue;
			if (map[ny][nx] == '0') continue;

			used[ny][nx] = 1;
			que.push({ ny, nx });
			tmp_cnt++;
		}
	}

	result2[result2_idx] = tmp_cnt;
	result2_idx++;
}