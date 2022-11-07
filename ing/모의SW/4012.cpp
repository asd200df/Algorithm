/* 요리사
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

int N, map[17][17], ingt[17], used[17], A[9], B[9];

void dfs(int lev) {
	if (lev == N) { // 종료 조건

		for (int i = 0; i < N / 2; i++) { // in A
			A[i] = ingt[i];
		}
		for (int j = N / 2; j < N; j++) { // in B
			B[j] = ingt[j];
		}

		// ... 조합 & operators
		for (int i = 0; i < N/2; i++) {
			for (int j = i + 1; j < N/2; j++) {
				A[i] + A[j]
			}
		}

		// ... abs & minimum update

		return;
	}


	for (int i = 0; i < N; i++) { // ingredient branch

		// if (ingt[lev] != 0) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		ingt[lev] = i;
		dfs(lev + 1);
		ingt[lev] = 0;
		used[i] = 0;
	}

}

void init() {

}

int main() {
	int T;
	cin >> T;

	for(int tc = 1; tc <= T; tc++){
		init();
		cin >> N;
	
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
			}
		}

		dfs(0);

		// cout << "#" << tc << " " << ... print minimum
	}

	return 0;
}


*/