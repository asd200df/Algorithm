// 최소비용 구하기 2 (11779) Gold[3]
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
int N, M, departure, destination;
typedef struct { int e, v; }node; // vector // queue
typedef struct { int v, pre; }node2; // dijkstra
vector<vector<node>> vec(1001);
node2 dijkstra[1001];

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
	cin >> N >> M;

	int is, ie, iv;
	for (int i = 0; i < M; i++) {
		cin >> is >> ie >> iv;
		vec[is].push_back({ ie, iv });
		// vec[ie].push_back({ is, iv }); // 양방향
	}

	cin >> departure >> destination;
}

// solution
void solve() {
	int result1 = -1;
	int result2 = -1;
	vector<int> result3;

	for (int i = 0; i < 1001; i++) { dijkstra[i].v = 21e8; }

	BFS(departure);

	int idx = destination;
	result3.push_back(destination);
	while(true) {
		int now = dijkstra[idx].pre;

		idx = now;
		if (0 == now) { break; }

		result3.push_back(now);
	}

	result1 = dijkstra[destination].v;
	result2 = result3.size();

	cout << result1 << "\n" << result2 << "\n";
	for (int i = result3.size() - 1; i >= 0; i--) {
		cout << result3[i] << " ";
	} cout << "\n";
}

// Breadth-First Search
void BFS(int ins) {
	queue<node> que;
	que.push({ ins, 0 });
	dijkstra[ins].v = 0;
	dijkstra[ins].pre = 0;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		if (dijkstra[now.e].v < now.v) { continue; }

		for (int i = 0; i < vec[now.e].size(); i++) {
			int nn = vec[now.e][i].e;
			int nv = dijkstra[now.e].v + vec[now.e][i].v;

			if (dijkstra[nn].v <= nv) { continue; }

			dijkstra[nn].v = nv;
			dijkstra[nn].pre = now.e;
			que.push({ nn, nv });
		}
	}
}