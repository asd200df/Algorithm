// 택배 배달과 수거하기 
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// solve
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long answer = -1;

	// setting
	long long total = 0;

	// search
	int DV = 0; // deliveries
	int PU = 0; // pickups
	for (int i = n - 1; i >= 0; i--) {
		DV -= deliveries[i];
		PU -= pickups[i];

		while (DV < 0 || PU < 0) { // 창고 갔다오기
			DV += cap;
			PU += cap;

			total += ((i + 1) * 2);
		}

	}

	// result update
	answer = total;

	// result return !
	return answer;
}