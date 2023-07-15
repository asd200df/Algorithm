// 알고리즘 수업 - 깊이 우선 탐색 2 (24480) Silver[2]
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
int N, M, R, cnt;
int used[100001];
int visit[100001];
vector<vector<int>> vec(100001);

// Function
void input();
void solve();
void DFS(int now);

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

	// sort // DESC 
	for (int i = 0; i <= N; i++) { 
		sort(vec[i].begin(), vec[i].end(), greater<int>()); 
	}

	// Call Funtion
	DFS(R);

	// Print result
	for (int i = 1; i <= N; i++) { cout << visit[i] << "\n"; }

}

// Depth-First Search
void DFS(int now) {
	visit[now] = ++cnt;
	used[now] = 1;

	for (int i = 0; i < vec[now].size(); i++) {
		int nx = vec[now][i];

		if (used[nx] == 1) { continue; }
		DFS(nx);
	}

}