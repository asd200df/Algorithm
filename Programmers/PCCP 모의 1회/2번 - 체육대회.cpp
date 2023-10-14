// 체육대회
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

// global
int N, M; // 학생, 종목 수
vector<vector<int>> ab;
bool used[11];
int maxi = -21e8;

// function
void DFS(int now, int sum);

// solve
int solution(vector<vector<int>> ability) {
	int answer = 0;

	// convert
	N = ability.size();
	M = ability[0].size();
	ab = ability;

	// func call
	DFS(0, 0);

	// debug
	// cout << N << " " << M;

	// update
	answer = maxi;

	// return result
	return answer;
}

// Depth-First Search
void DFS(int now, int sum) {
	if (now == M) {
		maxi = max(maxi, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		int next = ab[i][now];

		if (used[i]) { continue; }

		used[i] = true;
		DFS(now + 1, sum + next);
		used[i] = false;
	}
}