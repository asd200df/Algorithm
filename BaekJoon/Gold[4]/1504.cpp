// 특정한 최단 경로 (1504) Gold[4]
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
int N, E; // <= 800 <= 200,000
int dest[2];
typedef struct { int n, v; }node;
vector<vector<node>> vec(808);

// compare
struct compare {
	bool operator()(node a, node b) {
		return a.v > b.v;
	} // standard b
};

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
	cin >> N >> E;
	int v1, v2, vl;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2 >> vl;
		vec[v1].push_back({ v2, vl });
		vec[v2].push_back({ v1, vl }); // 양방향 연결
	}
	cin >> dest[0] >> dest[1];
}

// solution
void solve() {
	int mini;
	int candidate1 = 0;
	int candidate2 = 0;

	if (E == 0) { // Exception
		mini = 21e8;
	}
	else {
		candidate1 += BFS(1, dest[0]);
		candidate1 += BFS(dest[0], dest[1]);
		candidate1 += BFS(dest[1], N);

		candidate2 += BFS(1, dest[1]);
		candidate2 += BFS(dest[1], dest[0]);
		candidate2 += BFS(dest[0], N);

		mini = min(candidate1, candidate2);
	}

	if (mini >= 21e8) { cout << "-1\n"; }
	else { cout << mini << "\n"; }
}

// Breadth-First Search
int BFS(int st, int ed) {
	bool flag = false;
	int dijkstra[808];
	for (int i = 0; i < 808; i++) { dijkstra[i] = 21e8; }
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ st, 0 });
	dijkstra[st] = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (dijkstra[now.n] < now.v) { continue; }
		if (now.n == ed) { flag = true; }

		for (int i = 0; i < vec[now.n].size(); i++) {
			int nn = vec[now.n][i].n;
			int nv = vec[now.n][i].v + dijkstra[now.n];

			if (dijkstra[nn] < nv) { continue; }

			dijkstra[nn] = nv;
			pq.push({ nn, nv });
		}
	}

	if (flag) { return dijkstra[ed]; }
	else { return 21e8; }
}