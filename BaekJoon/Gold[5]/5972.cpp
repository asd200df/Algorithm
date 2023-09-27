// 택배 배송 (5972) Gold[5]
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
int N, M; // <= 50,000
int dijkstra[50003];
typedef struct { int n, v; }node;
vector<vector<node>> vec(50003);

// Compare
struct compare {
	bool operator()(node a, node b) {
		return a.v > b.v;
	} // standard b
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
	cin >> N >> M;

	int v1, v2, vl;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> vl;
		vec[v1].push_back({ v2, vl });
		vec[v2].push_back({ v1, vl }); // 양방향 연결
	}
}

// solution
void solve() {

	// dijk init
	for (int i = 0; i <= N; i++) { dijkstra[i] = 21e8; }

	// func call
	BFS();

	// print result 
	cout << dijkstra[N] << "\n";

}

// Breadth-First Search
void BFS() {
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ 1, 0 });
	dijkstra[1] = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (dijkstra[now.n] < now.v) { continue; }

		for (int i = 0; i < vec[now.n].size(); i++) {
			int nn = vec[now.n][i].n;
			int nv = vec[now.n][i].v;

			if (dijkstra[nn] <= (dijkstra[now.n] + nv)) { continue; }

			dijkstra[nn] = dijkstra[now.n] + nv;
			pq.push({ nn, dijkstra[nn] });
		}
	}
}