// 신고 결과 받기
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
unordered_map<string, int> idx_um;
int rep[1001], ret[1001];
int used[1001][1001];
vector<vector<string>> vec(200001);

// function
// -

// solve
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;

	// initialization
	string inp;
	for (int i = 0; i < id_list.size(); i++) {
		inp = id_list[i];
		idx_um[inp] = i;
	}

	// parsing
	for (int i = 0; i < report.size(); i++) {
		bool flag = true;
		string a, b;
		for (int j = 0; j < report[i].size(); j++) {
			if (report[i][j] == ' ') {
				flag = false;
				continue;
			}
			if (flag) { a += report[i][j]; }
			else { b += report[i][j]; }
		} // cout << a << b << "\n";
		vec[i].push_back(a);
		vec[i].push_back(b);
	}

	// process
	for (int i = 0; i < report.size(); i++) {
		int from = idx_um[vec[i][0]];
		int to = idx_um[vec[i][1]];

		if (used[from][to] == 1) { continue; }

		used[from][to] = 1;

		rep[to]++;
	}

	// update
	for (int i = 0; i < report.size(); i++) {
		int from = idx_um[vec[i][0]];
		int to = idx_um[vec[i][1]];

		if (used[from][to] >= 2) { continue; }

		used[from][to]++;

		if (rep[to] >= k) { ret[from]++; }
	}
	for (int i = 0; i < id_list.size(); i++) { answer.push_back(ret[i]); }

	// return result !
	return answer;
}