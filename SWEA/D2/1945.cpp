// 간단한 소인수분해
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, dat[5] = { 2, 3, 5, 7, 11 };
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		cout << "#" << tc << " ";
		for (int i = 0; i < 5; i++) {
			int ans = 0;
			while (1) {
				if ((N % dat[i]) == 0) {
					N /= dat[i];
					ans++;
				}
				else break;
			}
			cout << ans << " ";
		}

		cout << "\n";
	}

	return 0;
}