// ¼û¹Ù²ÀÁú 2 (12851) Gold[4]
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
int N, K; // <= 100,000
int cnt;
int dijkstra[100005];

// Function
void input();
void solve();
void BFS(int ins);

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
	cin >> N >> K;

	for (int i = 0; i < 100001; i++) { dijkstra[i] = 21e8; }
}

// solution
void solve() {
	int mini, cases;

	// BFS func call
	BFS(N);

	// result update
	mini = dijkstra[K];
	cases = cnt;

	// print result !
	cout << mini << "\n" << cases << "\n";
}

// Breadth-First Search
void BFS(int ins) {
	queue<int> que;
	que.push(ins);
	dijkstra[ins] = 0;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		if (now == K) { cnt++; }

		if (now * 2 < 100001 && dijkstra[now] + 1 <= dijkstra[now * 2]) {
			dijkstra[now * 2] = dijkstra[now] + 1;

			que.push(now * 2);
		}
		if (now + 1 < 100001 && dijkstra[now] + 1 <= dijkstra[now + 1]) {
			dijkstra[now + 1] = dijkstra[now] + 1;

			que.push(now + 1);
		}
		if (now - 1 >= 0 && dijkstra[now] + 1 <= dijkstra[now - 1]) {
			dijkstra[now - 1] = dijkstra[now] + 1;

			que.push(now - 1);
		}
	}

	return;
}