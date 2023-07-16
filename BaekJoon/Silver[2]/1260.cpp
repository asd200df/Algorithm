// DFS와 BFS (1260) Silver[2]
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
int N, M, V; // N <= 1005
int used[1005];
vector<vector<int>> vec(1005);

// Function
void input();
void solve();
void DFS(int now);
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
	cin >> N >> M >> V;
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

	// sort (ASC)
	for (int i = 1; i <= N; i++) { sort(vec[i].begin(), vec[i].end()); }

	// Call DFS Funtion
	used[V] = 1;
	DFS(V);
	cout << "\n";

	// initialization
	memset(used, 0, sizeof(used));

	// Call BFS Funtion
	BFS();
	cout << "\n";

}

// Depth-First Search
void DFS(int now) {

	cout << now << " ";

	for (int i = 0; i < vec[now].size(); i++) {
		int nx = vec[now][i];
		
		if (used[nx] == 1) { continue; }
		used[nx] = 1;
		DFS(nx);
	}

}

// Breadth-First Search
void BFS() {
	queue<int> que;
	que.push(V);

	cout << V << " ";
	used[V] = 1;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		for (int i = 0; i < vec[now].size(); i++) {
			int nx = vec[now][i];

			if (used[nx] == 1) { continue; }
			used[nx] = 1;
			
			cout << nx << " ";
			que.push(nx);
		}
	}
}