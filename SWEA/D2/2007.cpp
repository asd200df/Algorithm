// 패턴 마디의 길이
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int idx = 0;
string str;
char word[11];

bool isValid(int idx) {
	for (int i = 0; i < idx; i++) {
		if (word[i] != str[idx + i]) return false;
	}
	return true;
}

void init() {
	idx = 0;
	str.clear();
	memset(word, 0, sizeof(word));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		cin >> str;

		word[0] = str[0];
		while (1) {
			idx++;
			
			if (word[0] == str[idx]) {
				if (isValid(idx)) break;
			}
			word[idx] += str[idx];
		}

		/*
		// 갯수 세고 그 다음 그거 출력
		int tmp = 0, result = 0;
		for (int j = 0; j < str.length(); j+=idx) {
			for (int i = 0; i < idx; i++) {
				if (j + idx >= str.length()) break;
				if (word[i] == str[j + i]) {
					tmp++;
				}
				if (tmp == idx) {
					tmp = 0;
					result++;
				}
			}
		}
		*/

		cout << "#" << tc + 1 << " " << idx << "\n";
	}

	return 0;
}