// Á¤¼ö »ï°¢Çü
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

// solve
int solution(vector<vector<int>> triangle) {
	int answer = -21e8;

	// init
	vector<vector<int>> tri = triangle;
	vector<vector<int>> DP(501);

	// processor
	DP[0].push_back(tri[0][0]);
	for (int i = 1; i < tri.size(); i++) {

		DP[i].push_back(DP[i - 1][0] + tri[i][0]);
		for (int j = 1; j < tri[i].size() - 1; j++) {
			int now = tri[i][j];
			int n1 = now + DP[i - 1][j - 1];
			int n2 = now + DP[i - 1][j];
			int nmax = max(n1, n2);

			DP[i].push_back(nmax);
		}
		DP[i].push_back(DP[i - 1][tri[i].size() - 2] + tri[i][tri[i].size() - 1]);
	}

	/* debug
	for(int i = 0; i < tri.size(); i++){

		for(int j = 0; j < tri[i].size(); j++){
			int now = DP[i][j];

			cout << now << " ";
		} cout << "\n";
	} */

	// update
	for (int i = 0; i < DP[tri.size() - 1].size(); i++) {
		if (answer < DP[tri.size() - 1][i]) { answer = DP[tri.size() - 1][i]; }
	}

	// return result !
	return answer;
}