// 기능개발
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
queue<int> pro_que, spe_que;
vector<int> vec;

// function
// -

// solve
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	// first setting
	for (int i = 0; i < progresses.size(); i++) {
		pro_que.push(progresses[i]);
		spe_que.push(speeds[i]);
	}

	// Search
	queue<int> backup, init;
	int prefix, post;
	backup = pro_que;
	while (!backup.empty()) {
		prefix = pro_que.size(); // prefix size
		backup = init; // 초기화

		while (!pro_que.empty()) { // calculator
			int target = pro_que.front();
			int add = spe_que.front();

			pro_que.pop();
			spe_que.pop();

			target += add;

			backup.push(target);
			spe_que.push(add);
		}

		while (backup.front() >= 100) {
			backup.pop();
			spe_que.pop();
			if (backup.empty()) { break; }
		}

		pro_que = backup; // backup copy

		post = pro_que.size(); // post size

		if (prefix != post) {
			vec.push_back(prefix - post);
		}
	}

	// result update
	answer = vec;

	// return result
	return answer;
}