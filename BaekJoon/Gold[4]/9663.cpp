// N-Queen (9663) Gold[4]
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
int N; // <= 15
int cnt = 0;
int rc[20];
// bool used[20];

// Function
void input();
void solve();
void DFS(int now);
bool check(int row, int col);

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
	cin >> N;
}

// solution
void solve() {
	int result = -21e8;

	DFS(0);

	result = cnt;

	cout << result << "\n";
}

// Depth-First Search
void DFS(int now) {
	if (now == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		// pick : rc[row] = col;
		rc[now] = i;

		if (check(now, i)) { continue; }

		DFS(now + 1);
	}
}

// valid check
bool check(int row, int col) {

	for (int pre = 0; pre < row; pre++) {
		if (rc[pre] == col) { return true; }
		if (abs(rc[row] - rc[pre]) == abs(row - pre)) { return true; }
	}

	return false;
}