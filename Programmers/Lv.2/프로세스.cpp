// 프로세스
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
bool flag = false;
queue<int> que, num;
vector<int> vec;

// Function
// - 

// solve
int solution(vector<int> priorities, int location) {
	int answer = 0;

	// convert
	vec = priorities;
	for (int i = 0; i < priorities.size(); i++) {
		que.push(priorities[i]);
		num.push(i);
	}

	// sort
	sort(vec.begin(), vec.end(), greater<int>());

	// process
	int target, cnt;
	for (int i = 0; i < vec.size(); i++) {
		target = vec[i];

		for (int l = 0; l < que.size(); l++) {
			int now = que.front();
			int nownum = num.front();
			que.pop();
			num.pop();

			if (now == target) {
				cnt++;
				if (nownum == location) { flag = true; }
				break;
			}
			else {
				que.push(now);
				num.push(nownum);
			}
		}

		if (flag) {
			answer = cnt;
			break;
		}
	}

	// return result !
	return answer;
}