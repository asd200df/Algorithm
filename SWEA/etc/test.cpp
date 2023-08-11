/*   2번 문제(전원 연결)
#include<iostream>

using namespace std;
int map[14][14], sum;

void linkCore(int cnt, int y, int x) {  
	if (map[y][x + 1] == -1) {
		sum = cnt;
		return;
	}
	while (1) { // 우측
		linkCore(cnt + 1, y, x + 1);
	}
}}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;
		sum = 0;

		for (int i = 0; i < 14; i++) {  // map 초기화 
			for (int j = 0; j < 14; j++) {
				map[i][j] = -1;  // 벽 생성
			}
		}

		for (int i = 1; i <= N; i++) {  // map 입력 받기
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= N; i++) {  // core 연결하기
			for (int j = 1; j <= N; j++) {
				// 주위에 벽 있으면 continue
				if (map[i][j + 1] == -1 && map[i - 1][j] == -1 &&
					map[i + 1][j] == -1 && map[i][j - 1] == -1) continue;
				if (map[i][j] == 1) linkCore(0, i, j); 
			}
		}
		
	}

	return 0;
}
*/


/*  1번 문제 (전기차 충전소)
#include<iostream>

using namespace std;

int main() {
	int T, min;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int N, x[30], y[30], dis[30], sum;
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			cin >> x[i] >> y[i] >> dis[i];
		}

		min = 999;
		sum = 0;
		int flag = 0;
		for (int k = 0; k < N; k++) {
			for (int i = -15; i <= 15; i++) {
				for (int j = -15; j <= 15; j++) {
					int tmp1, tmp2;
					tmp1 = (x[k] - j) + (y[k] - i);
					tmp2 = (x[k+1] - j) + (y[k+1] - i);
					if (tmp1 < 0) tmp1 *= -1;
					if (tmp2 < 0) tmp2 *= -1;
					if (dis[k] < tmp1) continue;
					// if (dis[k+1] < tmp2) continue;
					if (tmp1 != 0 && min > tmp1) min = tmp1;
					
					if (dis[k + 1] >= tmp2 && tmp2 != 0 && tmp1 <= dis[k] &&
						tmp2 <= dis[k + 1]) {
						flag = 1;
						sum = tmp1 + tmp2;
						break;
					}
				}
				if (flag == 1) break;
			}
			if (flag == 1) break;
			sum += min;
		}

		cout << "#" << tc + 1 << " " << sum << endl;
	}

	return 0;
}
*/
