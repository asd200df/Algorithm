// ¿°¶ó´ë¿ÕÀÇ ÀÌ¸§ Á¤·Ä
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
vector<string> vec;

bool compare(string s, string t) {
	if (s.length() < t.length()) return 1;
	else if (s.length() > t.length()) return 0;
	else if (s.length() == t.length()) {
		return s < t;
	}
}

void init() { // initialization function
	N = 0;
	vec.clear();
}

int main() { // main
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		cin >> N;

		for (int i = 0; i < N; i++) {
			string tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}

		sort(vec.begin(), vec.end(), compare);

		cout << "#" << tc + 1 << endl;
		for (int i = 0; i < N; i++) { // sort test
			if (i != 0 && vec[i - 1] == vec[i]) continue;
			cout << vec[i] << endl;
		}
	}

	return 0;
}
