// 특정 거리의 도시 찾기 (18352) Silver[2]
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
int N, M, K, X;
int dijkstra[300001];
vector<vector<int>> vec(300001);
typedef struct { int num, val; }node;
// 2 ≤ N ≤ 300,000, 도시 수
// 1 ≤ M ≤ 1,000,000, 도로 수(간선)
// 1 ≤ K ≤ 300,000, 거리 정보
// 1 ≤ X ≤ N(300,000) 출발지

// Function
void input();
void init();
void solve();
void BFS();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	init();
	solve();

	return 0;
}

// input
void input() {
	cin >> N >> M >> K >> X;
	
	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		vec[v1].push_back(v2);
		// 양방향 아님 
	}
}

// initialization
void init() {
	// dijk N 만큼만 초기화 
	for (int i = 0; i <= N; i++) { dijkstra[i] = 21e8; }
}

// solution
void solve() {

	// BFS func call
	BFS();

	// check
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		int target = dijkstra[i];
		if (target == K) { flag = true; }
	}

	// print result
	if (flag == false) { cout << "-1\n"; }
	else {
		for (int i = 1; i <= N; i++) {
			int target = dijkstra[i];
			if (target == K) { 
				cout << i << "\n";
			}
		}
	}
}

// Breadth-First Search
struct compare {
	bool operator()(node a, node b) {
		return a.val > b.val;
	} // standard b !
};
void BFS() {
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ X, 0 });
	dijkstra[X] = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (dijkstra[now.num] < now.val) { continue; }

		for (int i = 0; i < vec[now.num].size(); i++) {
			int nxt = vec[now.num][i];
			int nval = dijkstra[now.num] + 1;

			if (dijkstra[nxt] < nval) { continue; }

			dijkstra[nxt] = nval;
			pq.push({ nxt, nval });
		}
	}
}