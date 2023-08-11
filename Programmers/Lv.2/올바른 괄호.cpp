// 올바른 괄호
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

bool solution(string s) {
	bool answer = false;

	stack<char> st;
	char now;
	for (int i = 0; i < s.size(); i++) {
		now = s[i];

		if (i == 0 && now == ')') {
			st.push(now);
			break;
		}

		if (now == '(') { st.push(now); }
		else { // now == ')'
			if (st.empty()) {
				st.push(now);
				break;
			}
			if (st.top() == '(') { st.pop(); }
		}
	}

	if (st.empty()) { answer = true; }

	return answer;
}