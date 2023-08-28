// 숨바꼭질 4 (13913) Gold[4]
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
int dijkstra[100005];
int path[100005];

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

	for (int i = 0; i < 100001; i++) {
		dijkstra[i] = 21e8;
	}
}

// solution
void solve() {
	int mini = 0;
	vector<int> ret, tmp;

	// BFS func call
	BFS(N);

	// arange	
	mini = dijkstra[K];
	int p = K;
	tmp.push_back(K);
	while (true) {
		if (path[p] == -1) { break; }

		tmp.push_back(path[p]);

		p = path[p];
	}

	// convert
	for (int i = tmp.size() - 1; i >= 0; i--) { ret.push_back(tmp[i]); }

	// print result !
	cout << mini << "\n";
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	} cout << "\n";
}

// Breadth-First Search
void BFS(int ins) {
	queue<int> que;
	que.push(ins);
	dijkstra[ins] = 0;
	path[ins] = -1;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		// 도착
		if (now == K) { return; }

		// 범위 벗어나면 갈 필요 없음 &&
		// 현재 위치 가중치 + 1 >= 다음 갈 곳 가중치 == 갈 필요 없음
		if (now * 2 < 100001 && dijkstra[now] + 1 < dijkstra[now * 2]) {
			dijkstra[now * 2] = dijkstra[now] + 1;

			path[now * 2] = now;

			que.push(now * 2);
		}
		if (now + 1 < 100001 && dijkstra[now] + 1 < dijkstra[now + 1]) {
			dijkstra[now + 1] = dijkstra[now] + 1;

			path[now + 1] = now;

			que.push(now + 1);
		}
		if (now - 1 >= 0 && dijkstra[now] + 1 < dijkstra[now - 1]) {
			dijkstra[now - 1] = dijkstra[now] + 1;

			path[now - 1] = now;

			que.push(now - 1);
		}
	}
}