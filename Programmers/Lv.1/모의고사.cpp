// 모의고사
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
vector<int> solution(vector<int> answers) {
	vector<int> answer;

	vector<int> one, two, thr;
	one = { 1, 2, 3, 4, 5 };
	two = { 2, 1, 2, 3, 2, 4, 2, 5 };
	thr = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int s1, s2, s3;
	s1 = 5;
	s2 = 8;
	s3 = 10;

	int cnt[3] = { 0 };
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == one[i % s1]) { cnt[0]++; }
		if (answers[i] == two[i % s2]) { cnt[1]++; }
		if (answers[i] == thr[i % s3]) { cnt[2]++; }
	}

	int maxi = cnt[0];
	maxi = max(maxi, cnt[1]);
	maxi = max(maxi, cnt[2]);

	for (int i = 0; i < 3; i++) {
		if (cnt[i] == maxi) { answer.push_back(i + 1); }
	}

	return answer;
}