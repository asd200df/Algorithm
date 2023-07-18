// 뱀과 사다리 게임 (16928) Gold[5]
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
int N, M, result;
typedef struct {
	int point, cost;
}node;
int map[103];	
int used[103];

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
	cin >> N >> M;

	int is, ie;
	for (int i = 0; i < N; i++) {
		cin >> is >> ie;
		map[is] = ie;
	}
	for (int i = 0; i < M; i++) {
		cin >> is >> ie;
		map[is] = ie;
	}
}

// solution
void solve() {

	// Call Function
	BFS();

	// Print result
	cout << result << "\n";

}

// Breadth-First Search
void BFS() {
	queue<node> que;
	que.push({ 1, 0 });

	used[1] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 1; i <= 6; i++) {
			int np = now.point + i;
			int nc = now.cost + 1;

			if (i < 0 || i >= 101) { continue; }
			if (map[np] != 0) { // Find  ladder & snake 
				que.push({ map[np], nc });
				continue;
			}

			// 도착지 발견
			if (np == 100) {
				result = nc;
				return;
			}

			if (used[np] == 1) { continue; }

			used[np] = 1;
			que.push({ np, nc });
		}
	}

}
