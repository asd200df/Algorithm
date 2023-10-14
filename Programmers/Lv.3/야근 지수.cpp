// 야근 지수
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
long long solution(int n, vector<int> works) {
	long long answer = 0;

	priority_queue<int> pq;

	for (int i = 0; i < works.size(); i++) { pq.push(works[i]); }

	for (int i = 0; i < n; i++) {
		int next = pq.top() - 1;
		pq.pop();
		pq.push(next);
	}

	long long sum = 0;
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();

		if (now <= 0) { continue; }

		sum += now * now;
	}

	answer = sum;

	return answer;
}