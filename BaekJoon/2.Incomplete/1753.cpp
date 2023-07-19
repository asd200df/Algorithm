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

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int V, E, K;	// 정점, 간선, 시작
int dijkstra[20001];
int used[20001];
typedef struct {
	int point, cost;
}node;
vector<vector<node>> vec(20001);

// Function
void input();
void solve();
void BFS();

// Main
int main(int argc, char** argv) {
	FastIO;

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> V >> E >> K;

	int is, ie, ic;
	for (int i = 0; i < E; i++) {
		cin >> is >> ie >> ic;
		vec[is].push_back({ ie, ic });
	}
}

// solution
void solve() {

	// initialization
	memset(dijkstra, -1, sizeof(dijkstra));

	// Call Function
	BFS();

	// Print Result 
	for (int i = 1; i <= V; i++) { 
		if (dijkstra[i] == -1) { cout << "INF\n"; }
		else { cout << dijkstra[i] << "\n"; }
	}
}

// Breadth_First Search
void BFS() {
	queue<node> que;
	que.push({ K, 0 });
	// used[K] = 1;
	dijkstra[K] = 0;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < vec[now.point].size(); i++) {
			int np = vec[now.point][i].point;
			int nc = now.cost + vec[now.point][i].cost;
			
			// if (used[np] == 1) { continue; }

			if (dijkstra[np] == -1) { dijkstra[np] = nc; }
			else if (dijkstra[np] < nc) { continue; }
			else { // dijkstra[np] > nc
				dijkstra[np] = nc;
			}


			// used[np] = 1;
			que.push({ np, nc });
		}
	}
}