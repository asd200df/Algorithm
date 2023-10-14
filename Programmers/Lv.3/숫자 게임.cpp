// 숫자 게임
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
int solution(vector<int> A, vector<int> B) {
	int answer = 0;

	int Alimit = A.size();
	int Blimit = B.size();

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int adx = 0;
	int bdx = 0;
	while (true) {
		int target = A[adx];
		int now = B[bdx];

		if (target < now) {
			adx++;
			bdx++;
			answer++;
		}
		else { bdx++; }

		if (adx == Alimit || bdx == Blimit) { break; }
	}

	return answer;
}