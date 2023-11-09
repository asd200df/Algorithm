// 짝지어 제거하기
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
int solution(string s) {
	int answer = -1;

	stack<char> st;
	st.push(s[0]);
	for (int i = 1; i < s.size(); i++) {
		char now = s[i];

		if (st.empty()) { st.push(now); }
		else {
			if (st.top() == now) {
				st.pop();
				continue;
			}
			else { st.push(now); }
		}
	}

	if (st.empty()) { answer = 1; }
	else { answer = 0; }

	return answer;
}