// ���ٲ��� 3 (13549) Gold[5]
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
int N, K; // <= 100,000
int dijkstra[100005];

// Function
void input();
void solve();
int BFS(int ins);

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
	cin >> N >> K;

	for (int i = 0; i < 100001; i++) { dijkstra[i] = 21e8; }
}

// solution
void solve() {
	int result = 0;

	result = BFS(N);

	cout << result << "\n";
}

// Breadth-First Search
int BFS(int ins) {
	queue<int> que;
	que.push(ins);
	dijkstra[ins] = 0;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		if (now == K) { return dijkstra[now]; }

		// �ϴ� ������ ����� �ȵǰ�,
		// ���� + ����ġ�� ���� �� �� ���� ũ�� queue�� ���� �ʿ䰡 ���� 
		if (now * 2 < 100001 && dijkstra[now] < dijkstra[now * 2]) {
			dijkstra[now * 2] = dijkstra[now];

			que.push(now * 2);
		}
		if (now + 1 < 100001 && dijkstra[now] + 1 < dijkstra[now + 1]) {
			dijkstra[now + 1] = dijkstra[now] + 1;

			que.push(now + 1);
		}
		if (now - 1 >= 0 && dijkstra[now] + 1 < dijkstra[now - 1]) {
			dijkstra[now - 1] = dijkstra[now] + 1;

			que.push(now - 1);
		}
	}

	return -8;
}