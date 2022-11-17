// 두 개의 숫자열
#include<iostream>

using namespace std;

int main() {
	int T, arr[20], brr[20], N, M, temp, max;

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) { cin >> arr[i]; }
		for (int i = 0; i < M; i++) { cin >> brr[i]; }

		max = 0;

		if (N < M) {
			for (int i = 0; i <= M - N; i++) {
				temp = 0;
				for (int j = 0; j < N; j++) {
					temp += arr[j] * brr[j + i];
				}
				if (max < temp) max = temp;
			}
		}

		if (N > M) {
			for (int i = 0; i <= N - M; i++) {
				temp = 0;
				for (int j = 0; j < M; j++) {
					temp += brr[j] * arr[j + i];
				}
				if (max < temp) max = temp;
			}
		}

		cout << "#" << tc + 1 << " " << max << endl;
	}

	return 0;
}
