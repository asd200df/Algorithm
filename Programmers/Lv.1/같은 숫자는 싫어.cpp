// 같은 숫자는 싫어
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
vector<int> solution(vector<int> arr) {
	vector<int> answer;

	stack<int> st;
	st.push(arr[0]);
	for (int i = 1; i < arr.size(); i++) {
		int target = st.top();

		if (target == arr[i]) { continue; }

		st.push(arr[i]);
	}

	vector<int> vec;
	int temp = 0;
	while (!st.empty()) {
		temp = st.top();
		st.pop();
		vec.push_back(temp);
	}

	for (int i = vec.size() - 1; i >= 0; i--) {
		answer.push_back(vec[i]);
	}

	return answer;
}