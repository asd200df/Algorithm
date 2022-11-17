// 평균값 구하기
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	cout.precision(0);
	cout << fixed;

	for (int tc = 0; tc < T; tc++) {
		float ret = 0;

		for (int i = 0; i < 10; i++) {
			int tmp;
			cin >> tmp;
			ret += tmp;
		}

		cout << "#" << tc + 1 << " " << ret / 10 << "\n";
	}

	return 0;
}