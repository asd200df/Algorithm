/* 아름이의 돌 던지기
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int hum[1001], su, min = 21e8;
		cin >> su;

		int cnt = 0;
		for (int i = 0; i < su; i++) {
			cin >> hum[i];
			if (abs(hum[i]) < min) {
				min = abs(hum[i]);
				cnt = 1;
			}
			else if (abs(hum[i]) == min) { cnt++; }
		}

		cout << "#" << tc + 1 << " " << min << " " << cnt << "\n";
	}

	return 0;
}
*/