// 홀수만 더하기
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int ret = 0;

		for (int i = 0; i < 10; i++) {
			int tmp;
			cin >> tmp;

			if ((tmp % 2) == 1) ret += tmp;
		}
		cout << "#" << tc + 1 << " " << ret << "\n";
	}

	return 0;
}