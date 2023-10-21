// ÇÇ·Îµµ
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// global
int maxi = -21e8;
vector<vector<int>> dg;

// function
void DFS(int lev, int pi);

// solve
int solution(int k, vector<vector<int>> dungeons) {
	int answer = -1;

	dg = dungeons;

	DFS(0, k);

	answer = maxi;

	return answer;
}

// Depth-First Search
bool used[10];
void DFS(int lev, int pi) {
	if (lev > maxi) { maxi = lev; }

	for (int i = 0; i < dg.size(); i++) {
		int mpi = dg[i][0];
		int npi = dg[i][1];

		if (pi < mpi) { continue; }
		if (pi < npi) { continue; }
		if (used[i]) { continue; }

		used[i] = true;
		DFS(lev + 1, pi - npi);
		used[i] = false;
	}
}