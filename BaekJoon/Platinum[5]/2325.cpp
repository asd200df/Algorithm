// 개코전쟁 (2325) Platinum[5]
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
int N, M; // <= 1,000 // <= 499000
int t1, t2, bfs_ret;
bool flag = true;
int dijkstra[1005];
int pre[1005];
typedef struct { int n, v; }node;
vector<vector<node>> vec(1005);
int temp[1005];

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
	cin >> N >> M;

	int v1, v2, vl;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> vl;
		vec[v1].push_back({ v2, vl });
		vec[v2].push_back({ v1, vl }); // 양방향
	}
}

// solution
void solve() {
	// dijkstra 초기화
	for (int i = 0; i <= N; i++) { dijkstra[i] = 21e8; }

	// 최단거리 찾기
	BFS();

	// 경로 파괴하면서 최단거리 찾기 (+ dijkstra init n)
	flag = false;
	int maxi = -21e8;
	for (int i = 2; i <= N; i++) {
		for (int i = 0; i <= N; i++) { dijkstra[i] = 21e8; }
		t1 = i;
		t2 = pre[i];
		BFS();
		maxi = max(maxi, dijkstra[N]);
	}

	// 결과 출력 
	cout << maxi << "\n";
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
			int nv = dijkstra[now.n] + vec[now.n][i].v;

			if (dijkstra[nn] <= nv) { continue; }
			if (flag) { pre[nn] = now.n; }
			else { 
				if (t1 == nn && t2 == now.n) { continue; }
				if (t1 == now.n && t2 == nn) { continue; }
			}

			temp[nn] = now.n;
			dijkstra[nn] = nv;
			pq.push({ nn, nv });
		}
	}
}