// 프린터 큐 (1966) Silver[3]
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
int T, N, M;
int prio[101];
typedef struct {
	int coordinate;
	int priority;
}node;
queue<node> que;

// Function
void init();
void input();
void solve();

// Main
int main(int argc, char** argv) {
	FastIO;

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		input();
		if (N == 1) { 
			cout << "1\n";
			continue;
		}
		solve();
	}

	return 0;
}

// initialization
void init() {
	N = M = 0;
	memset(prio, 0, sizeof(prio));
	que = queue<node>();
}

// input
void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> prio[i];
		que.push({ i, prio[i] });
	}
}

// solution
void solve() {

	sort(prio, prio + N, greater<int>());

	int idx = 0;
	node now;
	while (!que.empty()) {
		now = que.front();
		que.pop();

		if (now.priority == prio[idx]) {
			idx++;
			if (now.coordinate == M) { break; }
			continue;
		}

		que.push(now);
	}

	cout << idx << "\n";
}