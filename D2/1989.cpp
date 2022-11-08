// 초심자의 회문 검사 
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
	int mid = s.length() / 2;

	for (int i = 0; i < mid; i++) {
		if (s[i] != s[s.length() - 1 - i]) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		string str;
		cin >> str;

		if (isValid(str)) cout << "#" << tc + 1 << " 1\n";
		else cout << "#" << tc + 1 << " 0\n";
	}

	return 0;
}
