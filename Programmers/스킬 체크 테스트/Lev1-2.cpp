// 스킬 체크 테스트 Lev1-2
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
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	// processor
	for (int i = 0; i < arr1.size(); i++) {
		int a1 = arr1[i];
		int a2 = arr2[i];
		string s1, cs1;
		string s2, cs2;

		int div;
		int mod;
		while (a1 > 0) {
			div = a1 / 2;
			mod = a1 % 2;
			a1 = div;
			s1 += to_string(mod);
		}
		int diff = n - s1.size();
		while (diff--) { cs1 += "0"; }
		for (int j = s1.size() - 1; j >= 0; j--) {
			cs1 += s1[j];
		}

		div = 0;
		mod = 0;
		while (a2 > 0) {
			div = a2 / 2;
			mod = a2 % 2;
			a2 = div;
			s2 += to_string(mod);
		}
		diff = n - s2.size();
		while (diff--) { cs2 += "0"; }
		for (int j = s2.size() - 1; j >= 0; j--) {
			cs2 += s2[j];
		}

		string ret;
		for (int j = 0; j < n; j++) {
			if (cs1[j] == '1' || cs2[j] == '1') { ret += "#"; }
			else if (cs1[j] == '0' && cs2[j] == '0') { ret += " "; }
		}

		answer.push_back(ret);
	}

	return answer;
}