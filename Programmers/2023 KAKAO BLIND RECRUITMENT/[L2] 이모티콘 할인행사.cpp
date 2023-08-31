// 이모티콘 할인행사
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
int per_arr[1000001];
typedef struct { int num, sum; } node;
node result;
vector<vector<int>> user;
vector<int> emo;

// Function
void DFS(int now);
void cal();

// Solve
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;

	// convert
	result.num = -21e8;
	result.sum = -21e8;
	user = users;
	emo = emoticons;

	// DFS func call
	DFS(0);

	// update 
	answer.push_back(result.num);
	answer.push_back(result.sum);

	// return 
	return answer;
}

// Depth-First Search
void DFS(int now) {
	if (now == emo.size()) {
		cal();

		return;
	}

	for (int per = 10; per <= 40; per += 10) {

		per_arr[now] = per;
		DFS(now + 1);
		per_arr[now] = 0;
	}
}

// calculator
void cal() {
	node total;
	total.num = 0;
	total.sum = 0;
	int cus[101];

	/* debug
	for(int i = 0; i < 2; i++) { cout << per_arr[i] << " "; }
	cout << "\n";
	*/

	// search
	for (int i = 0; i < user.size(); i++) {
		cus[i] = 0;

		for (int j = 0; j < emo.size(); j++) {
			if (user[i][0] > per_arr[j]) { continue; }
			cus[i] += emo[j] * ((100 - per_arr[j]) * 0.01);
			// cout << (100 - per_arr[j]) * 0.01 << " " << per_arr[j] << "\n";
		}

		if (user[i][1] <= cus[i]) {
			total.num++;
			cus[i] = 0;
		}

	}

	// update
	for (int i = 0; i < user.size(); i++) { total.sum += cus[i]; }

	// maximum check
	if (result.num < total.num) {
		result.num = total.num;
		result.sum = total.sum;
	}
	else if (result.num == total.num) {
		if (result.sum < total.sum) {
			result.sum = total.sum;
		}
	}

	return;
}