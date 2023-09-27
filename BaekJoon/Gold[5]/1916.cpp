// 최소비용 구하기 (1916) Gold[5]
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
int N, M; // 1 <= 1,000 // 1 <= 100,000
int start_point, end_point;
int dijkstra[1005];
typedef struct { int num, val; }node;
vector<vector<node>> vec(1005);

// priority_queue compare
struct compare {
	bool operator()(node a, node b) {
		return a.val > b.val;
	} // standard == b
};

// Function
void init();
void input();
void solve();
void BFS();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	input();
	solve();

	return 0;
}

// initialization
void init() {
	for (int i = 0; i < 1005; i++) {
		dijkstra[i] = 21e8;
	}
}

// input
void input() {
	cin >> N >> M;

	int v1, v2, vl;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2 >> vl;
		vec[v1].push_back({ v2, vl });
		// vec[v2].push_back({ v1, vl }); // if 양방향
	}

	cin >> start_point >> end_point;
}

// solution
void solve() {

	// func call
	BFS();

	// print result !
	cout << dijkstra[end_point] << "\n";
}

// Breadth-First Search
void BFS() {
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ start_point, 0 });
	dijkstra[start_point] = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (dijkstra[now.num] < now.val) { continue; }

		for (int i = 0; i < vec[now.num].size(); i++) {
			int nxt = vec[now.num][i].num;
			int nval = vec[now.num][i].val;

			if (dijkstra[nxt] <= (dijkstra[now.num] + nval)) { continue; }

			dijkstra[nxt] = dijkstra[now.num] + nval;
			pq.push({ nxt, dijkstra[nxt] });
		}
	}
}