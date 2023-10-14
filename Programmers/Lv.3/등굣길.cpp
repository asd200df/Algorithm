// µî±·±æ
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
int DP[105][105];
bool pud[105][105];

// solve
int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;

	// puddles check
	for (int i = 0; i < puddles.size(); i++) {
		int idx[2];
		for (int j = 0; j < puddles[i].size(); j++) { idx[j] = puddles[i][j]; }
		pud[idx[1]][idx[0]] = true;
	}

	// processor
	DP[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (pud[i][j]) { continue; }

			if (pud[i - 1][j] == false) { DP[i][j] = (DP[i - 1][j] + DP[i][j]) % 1000000007; }
			if (pud[i][j - 1] == false) { DP[i][j] = (DP[i][j - 1] + DP[i][j]) % 1000000007; }
		}
	}

	/* debug
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << DP[i][j] << " ";
		} cout << "\n";
	} */

	// update result
	answer = DP[n][m];

	// return result
	return answer;
}