// Ã¼À°º¹
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

bool used[35] = { false };

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	int sum = (n - lost.size());

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	queue<int> que;
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				used[lost[i]] = true;
				sum++;
			}
		}
		if (used[lost[i]]) { continue; }
		que.push(lost[i]);
	}

	while (!que.empty()) {
		int now = que.front();
		que.pop();

		for (int i = 0; i < reserve.size(); i++) {
			int target = reserve[i];

			if (used[target]) { continue; }
			if (1 == (abs(now - target)) || 0 == (abs(now - target))) {
				used[target] = true;
				sum++;
				break;
			}
		}
	}

	answer = sum;

	return answer;
}