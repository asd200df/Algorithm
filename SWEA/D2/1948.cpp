// 날짜 계산기
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

int date[13] = { 0, 31, 28, 31, 30, 31, 30, 
				31, 31, 30, 31, 30, 31};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int m1, d1, m2, d2, ret = 0;
		cin >> m1 >> d1 >> m2 >> d2;

		if (m1 == m2) { // same month
			cout << "#" << tc + 1 << " " <<
				d2 - d1 + 1 << "\n";
		}
		else { // different month
			ret += date[m1] - d1 + 1; // first
			for (int i = 0; i < m2 - m1 - 1; i++) {
				ret += date[m1 + i + 1];
			}
			ret += d2; // last
			cout << "#" << tc + 1 << " " << ret << "\n";
		}
	}

	return 0;
}