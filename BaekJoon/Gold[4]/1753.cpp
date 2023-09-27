// 최단경로 (1753) Gold[4]
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
int V, E; // <= 20,000 <= 300,000
int start_point;
int dijkstra[20005];
typedef struct { int num, val; }node;
vector<vector<node>> vec(20005);
struct compare {
	bool operator()(node a, node b) {
		return a.val > b.val;
	} // b 기준 
};

// Function
void input();
void solve();
void BFS();

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
	cin >> V >> E;
	cin >> start_point;

	int v1, v2, vl;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2 >> vl;
		vec[v1].push_back({ v2, vl });
		// vec[v2].push_back({ v1, vl }); // 양방향 필요시
	}
}

// solution
void solve() {
	// dijk init
	for (int i = 0; i <= V; i++) { dijkstra[i] = 21e8; }

	// func call
	BFS();

	// print result
	for (int i = 1; i <= V; i++) {
		int result = dijkstra[i];
		if (result == 21e8) { cout << "INF\n"; }
		else { cout << result << "\n"; }
	}
}

// Breadth-First Search
void BFS() {
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ start_point, 0 });
	dijkstra[start_point] = 0;

	while (!pq.empty()) {
		int now = pq.top().num;
		int nv = pq.top().val;
		pq.pop();

		if (dijkstra[now] < nv) { continue; }

		for (int i = 0; i < vec[now].size(); i++) {
			int nxt = vec[now][i].num;
			int nvl = vec[now][i].val;

			if (dijkstra[nxt] <= (dijkstra[now] + nvl)) { continue; }

			dijkstra[nxt] = dijkstra[now] + nvl;
			pq.push({ nxt, dijkstra[nxt] });
		}
	}
}