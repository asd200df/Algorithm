// 촌수계산 (2644) Silver[2]
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
int N, M, T1, T2; // N <= 100, T1 == target1 ...
int dfs_ret;
int used[101];
vector<vector<int>> vec(101);

// Function
void input();
void solve();
void DFS(int cnt, int now);

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
	cin >> N;

	cin >> T1 >> T2;

	cin >> M;

	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;

		vec[v1].push_back(v2);
		vec[v2].push_back(v1); // 양방향 연결
	}
}

// solution
void solve() {
	int result = 0;

	// DFS func call
	DFS(0, T1);

	// result update
	if (dfs_ret == 0) { result = -1; }
	else { result = dfs_ret; }

	// print result !
	cout << result << "\n";
}

// Depth-First Search
void DFS(int cnt, int now) {
	if (now == T2) {
		dfs_ret = cnt;
		return;
	}

	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];
		
		if (used[next] == 1) { continue; }

		used[next] = 1;
		DFS(cnt + 1, next);
		used[next] = 0;
	}
}