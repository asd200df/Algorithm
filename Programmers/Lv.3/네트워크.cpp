// 네트워크
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Global
int used[202];
vector<vector<int>> com(202);

// Function
void BFS(int n);

// solve
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	// copy
	com = computers;

	// BFS func call
	for (int i = 0; i < n; i++) {
		// cout << used[i] << " ";
		if (used[i] == 1) { continue; }
		BFS(i);
		answer++;
	}

	// return result !
	return answer;
}

// Breadth-First Search
void BFS(int n) {
	queue<int> que;
	que.push(n);
	used[n] = 1;

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		for (int i = 0; i < com[now].size(); i++) {
			int temp = com[now][i];

			if (temp == 0) { continue; }

			int next = i;

			if (used[next] == 1) { continue; }

			used[next] = 1;

			que.push(next);
		}
	}
}