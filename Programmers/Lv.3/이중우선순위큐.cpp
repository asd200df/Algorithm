// 이중우선순위큐
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
vector<int> solution(vector<string> operations) {
	vector<int> answer;
	unordered_map<string, bool> um;
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	vector<string> oper = operations;

	// processor
	for (int i = 0; i < oper.size(); i++) {
		char order = oper[i][0];
		string temp = "";
		int num;

		// parsing
		for (int j = 2; j < oper[i].size(); j++) {
			temp += oper[i][j];
		} num = stoi(temp);

		// operating
		if (order == 'I') {
			max_pq.push(num);
			min_pq.push(num);
			um[to_string(num)] = true;
		}
		else { // order == 'D'
			int temp;
			if (num == 1) {
				while (!max_pq.empty()) {
					temp = max_pq.top();
					max_pq.pop();
					if (um[to_string(temp)] == false) { continue; }
					um[to_string(temp)] = false;
					break;
				}
			}
			else { // num == -1
				while (!min_pq.empty()) {
					temp = min_pq.top();
					min_pq.pop();
					if (um[to_string(temp)] == false) { continue; }
					um[to_string(temp)] = false;
					break;
				}
			}
		}
	}

	// Valid Check
	if (max_pq.empty() || min_pq.empty()) {
		for (int i = 1; i <= 2; i++) { answer.push_back(0); }
	}
	else {
		while (!max_pq.empty()) {
			int now = max_pq.top();
			max_pq.pop();
			if (um[to_string(now)] == false) { continue; }
			answer.push_back(now);
			break;
		}
		while (!min_pq.empty()) {
			int now = min_pq.top();
			min_pq.pop();
			if (um[to_string(now)] == false) { continue; }
			answer.push_back(now);
			break;
		}
	}

	// return result !
	return answer;
}