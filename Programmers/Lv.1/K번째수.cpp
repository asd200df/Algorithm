// K번째수
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
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	vector<int> vec;
	int st, ed, tar;
	for (int i = 0; i < commands.size(); i++) {
		st = commands[i][0] - 1;
		ed = commands[i][1] - 1;
		tar = commands[i][2] - 1;

		// 자르기
		for (int j = st; j <= ed; j++) { vec.push_back(array[j]); }

		// 정렬
		sort(vec.begin(), vec.end());

		// answer update
		answer.push_back(vec[tar]);

		// vector initialization
		vec.clear();
	}

	return answer;
}