// 바이러스 (2606) Silver[3]
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
int N, M, cnt;
int used[102];
vector<vector<int>> vec(102);

// Function
void input();
void solve();
void BFS(int start);

// Main
int main(int argc, char** argv) {
	FastIO;

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N >> M;
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

	BFS(1);

	for (int i = 1; i <= N; i++) { if (used[i] == 1) { cnt++; } }

	// int debug = 0;
	cout << cnt - 1 << "\n";
}

// Breadth-First Search
void BFS(int start) {
	queue<int> que;
	que.push(start);

	used[start] = 1;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];

			if (used[next] == 1) { continue; }
			used[next] = 1;

			que.push(next);
		}
	}

}