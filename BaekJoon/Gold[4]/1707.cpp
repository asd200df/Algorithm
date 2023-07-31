// 이분 그래프 (1707) Gold[4]
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
int V, E, K, team = 1;
int group[20001];
vector<vector<int>> vec(20001);

// Function
void init();
void input();
void solve();
void BFS(int ins);
void gc(int type);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	for (int tc = 0; tc < K; tc++) {
		init();
		input();
		solve();
	}

	return 0;
}

// initialization
void init() {
	team = 1;
	memset(group, 0, sizeof(group));
	for (int i = 0; i < 20001; i++) { vec[i].clear(); }
}

// input
void input() {
	cin >> V >> E;

	int v1, v2;
	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2;
		vec[v1].push_back(v2);
		vec[v2].push_back(v1); // 양방향 연결
	}
}

// solution
void solve() {
	bool flag = true;

	// Search
	for (int i = 1; i <= V; i++) {
		if (group[i] != 0) { continue; }
		BFS(i);
	}

	// Valid Check
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			int idx = vec[i][j];
			if (group[i] == group[idx]) { flag = false; }
		}
	}

	// Print result 
	if (flag) { cout << "YES\n"; }
	else { cout << "NO\n"; }
}

// Breadth-First Search
void BFS(int ins) {
	queue<int> que;
	que.push(ins);
	group[ins] = team;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		if (group[now] == team) { gc(team); }

		for (int i = 0; i < vec[now].size(); i++) {
			int nv = vec[now][i];

			if (group[nv] != 0) { continue; }

			group[nv] = team;
			que.push(nv);
		}
	}
}

// group change
void gc(int type) {
	if (type == 1) { team = 2; }
	else { team = 1; }
}