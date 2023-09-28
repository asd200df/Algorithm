// K번째 최단경로 찾기 (1854) Platinum[4]
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
int N, M, K; // 1 <= 1,000 // 0 <= 2,000,000 // 1 <= 100
typedef struct { int n, v; }node;
vector<vector<node>> vec(1005);
vector<vector<int>> dijkstra(1005);

// compare
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
	cin >> N >> M >> K;

	int v1, v2, vl;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> vl;
		vec[v1].push_back({ v2, vl });
		// vec[v2].push_back({ v1, vl }); // 양방향 고려 
	}
}

// solution
void solve() {

	BFS();

	int debug = 0;

	for (int i = 1; i <= N; i++) {
		if (dijkstra[i].size() < K) { cout << "-1\n"; }
		else { cout << dijkstra[i][K - 1] << "\n"; }
	}

}

// Breadth-First Search
void BFS() {
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ 1, 0 });
	// dijkstra[1].push_back(0);

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (dijkstra[now.n].size() > K) { continue; }
		dijkstra[now.n].push_back(now.v);
		
		for (int i = 0; i < vec[now.n].size(); i++) {
			int nn = vec[now.n][i].n;
			int nv = vec[now.n][i].v + now.v;

			pq.push({ nn, nv });
		}
	}
}