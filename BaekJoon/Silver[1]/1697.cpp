// ¼û¹Ù²ÀÁú (1697) Silver[1]
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
int N, K;
int used[100001];
typedef struct {
	int point, cnt;
}node;

// Function
void insol();
int BFS(node first);

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input & solution
void insol() {
	cin >> N >> K;

	int result = 0;

	if (N != K) { result = BFS({ N, 0 }); }

	cout << result << "\n";
}

// Breadth-First Search
int BFS(node first) {
	queue<node> que;
	que.push(first);

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int type = 1; type < 4; type++) {
			int next_p = now.point;
			int next_c = now.cnt + 1;

			if (type == 1) {  // reverse (-1)
				next_p--; 
			}
			else if (type == 2) { // forward (+1)
				next_p++; 
			}
			else if (type == 3) { // teleport (*2)
				next_p *= 2; 
			}

			if (next_p < -2 || next_p > 100000) { continue; }
			if (used[next_p] == 1) { continue; }

			used[next_p] = 1;

			if (next_p == K) { return next_c; }

			que.push({ next_p, next_c });
		}
	}

}