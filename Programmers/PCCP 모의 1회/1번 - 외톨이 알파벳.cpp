// 외톨이 알파벳
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

string solution(string input_string) {
	string answer = "";

	int alpha[30] = { 0 };
	alpha[input_string[0] - 'a']++;
	bool flag = true;

	for (int i = 1; i < input_string.size(); i++) {
		char pre = input_string[i - 1];
		char now = input_string[i];

		if (pre == now) { continue; }

		alpha[now - 'a']++;
	}

	for (int i = 0; i < 26; i++) { // 0 ~ 25
		if (alpha[i] > 1) {
			flag = false;
			answer += ('a' + i);
		}
	}

	if (flag) { answer = 'N'; }

	return answer;
}