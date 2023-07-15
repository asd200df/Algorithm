// 알고리즘 수업 - 너비 우선 탐색 1 (24444) Silver[2]
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
int N, M, R; // N <= 100,000
int used[100001];
int result[100001];
vector<vector<int>> vec(100001);

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
	cin >> N >> M >> R;
	int st = 0;
	int ed = 0;
	for (int i = 0; i < M; i++) {
		cin >> st >> ed;
		vec[st].push_back(ed);
		vec[ed].push_back(st); // 양방향 연결 
	}
}

// solution
void solve() {

	// sort
	for (int i = 1; i <= N; i++) { sort(vec[i].begin(), vec[i].end()); }

	// Call Funtion
	BFS();

	// Print result
	for (int i = 1; i <= N; i++) { cout << result[i] << "\n"; }

}

// Breadth-First Search
void BFS() {
	int cnt = 1;
	queue<int> que;
	que.push(R);
	used[R] = 1;
	result[R] = cnt;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int nx = vec[now][i];

			if (used[nx] == 1) { continue; }
			used[nx] = 1;

			result[nx] = ++cnt;
			que.push(nx);
		}
		
	}

}