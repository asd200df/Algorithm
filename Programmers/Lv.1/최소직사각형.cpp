// 최소직사각형
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
int solution(vector<vector<int>> sizes) {
	int answer = 0;

	int miA = 0;
	int mxB = 0;
	for (int i = 0; i < sizes.size(); i++) {
		int a = min(sizes[i][0], sizes[i][1]);
		int b = max(sizes[i][0], sizes[i][1]);

		miA = max(miA, a);
		mxB = max(mxB, b);
	}

	answer = (miA * mxB);

	return answer;
}