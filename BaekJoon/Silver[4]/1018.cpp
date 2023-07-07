// 체스판 다시 칠하기 (1018) Silver[4]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N, M; // <= 50
int mini = 21e8;
char map[55][55];

// Function
void input();
void solve();
void check(int y, int x);

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
			cin >> map[i][j];
		}
	}
}

// solution
void solve() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 7 >= N) { continue; }
			if (j + 7 >= M) { continue; }
			check(i, j);
		}
	}

	cout << mini << "\n";
}

// valid check
void check(int y, int x) {
	int w_cnt = 0;
	int b_cnt = 0;
	int temp = 0;

	for (int i = y; i <= y + 7; i++) {
		for (int j = x; j <= x + 7; j++) {
			temp = (j + i) % 2;

			// W first, B first
			if (temp == 0) {
				if (map[i][j] != 'W') { w_cnt++; }
				if (map[i][j] != 'B') { b_cnt++; }
			}
			else if (temp == 1) {
				if (map[i][j] != 'B') { w_cnt++; }
				if (map[i][j] != 'W') { b_cnt++; }
			}
		}
	}

	if (w_cnt < b_cnt) {
		if (w_cnt < mini) { mini = w_cnt; }
	}
	else {
		if (b_cnt < mini) { mini = b_cnt; }
	}
}