// 어디에 단어가 들어갈 수 있을까 
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
		int map[16][16] = { 0 }, N, K, result = 0;
		cin >> N >> K;

		for (int i = 0; i < N; i++) { // input(map array)
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		// 연속된 수 찾기 위한 cnt 변수
		int cnt = 0;
		for (int y = 0; y < N; y++) { // row check
			for (int x = 0; x < N; x++) {
				if (map[y][x] == 1) cnt++;
				else cnt = 0;

				if (cnt == K && map[y][x + 1] == 0) {
					result++;
					cnt = 0;
				}
			}
			cnt = 0;
		}

		cnt = 0;
		for (int x = 0; x < N; x++) { // column check
			for (int y = 0; y < N; y++) {
				if (map[y][x] == 1) cnt++;
				else cnt = 0;

				if (cnt == K && map[y + 1][x] == 0) {
					result++;
					cnt = 0;
				}
			}
			cnt = 0;
		}
		
		cout << "#" << tc + 1 << " " << result << "\n";
	}

	return 0;
}