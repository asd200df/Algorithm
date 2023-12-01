// 파티 (1238) Gold[3]
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Global
int N, M, X;
int AtoB[1003];
typedef struct { int v, w; }node;
vector<vector<node>> vec(1003);

// Function
void input();
void solve();
int BFS(int st, int ed);

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
	cin >> N >> M >> X;
	
	int v1, v2, w;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> w;

		vec[v1].push_back({ v2, w }); // 단방향 연결
	}
}

// solution
void solve() {
	int result = -21e8;

	// 1st Search
	for (int now = 1; now <= N; now++) {
		if (now == X) { continue; }
		int rv = BFS(now, X);
		AtoB[now] = rv;
	}

	// Secondary Search
	for (int now = 1; now <= N; now++) {
		if (now == X) { continue; }
		int rv = BFS(X, now);
		AtoB[now] += rv;
	}

	// Last Search && Update
	for (int i = 0; i < 1001; i++) {
		if (result < AtoB[i]) { result = AtoB[i]; }
	}

	// Print result !
	cout << result << "\n";
}

// Breadth-First Search
int BFS(int st, int ed) {
	int dijkstra[1003];
	queue<int> que;

	for (int i = 0; i < 1003; i++) { dijkstra[i] = 21e8;	}
	que.push(st);
	dijkstra[st] = 0;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int nn = vec[now][i].v;
			int nw = dijkstra[now] + vec[now][i].w;

			if (dijkstra[nn] <= nw) { continue; }

			dijkstra[nn] = nw;
			que.push(nn);
		}
	}

	return dijkstra[ed];
}