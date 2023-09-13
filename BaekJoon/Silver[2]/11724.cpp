// 연결 요소의 개수 (11724) Silver[2]
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
int N, M; // <= 1,000, <= Nx(N-1)/2
bool used[499505];
vector<vector<int>> vec(499505);

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

	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		vec[v1].push_back(v2);
		vec[v2].push_back(v1);
	}
}

// solution
void solve() {
	int cnt = 0;

	for (int now = 1; now <= N; now++) {

		if (used[now]) { continue; }
		BFS(now);
		cnt++;
	}

	cout << cnt << "\n";
}

// Breadth-First Search
void BFS(int ins) {
	queue<int> que;
	que.push(ins);
	used[ins] = true;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];

			if (used[next]) { continue; }

			used[next] = true;

			que.push(next);
		}
	}
}