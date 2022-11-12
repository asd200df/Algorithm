// 보호 필름
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

// global
int D, W, K, minimum = 21e8, flag = 0;
int map[14][21], backup[14][21];
int lineSaverA[15], lineSaverB[15];

void BT() { // Back tracking func
	copy(&backup[0][0], &backup[D][W], &map[0][0]);
}

bool isValid() { // Valid Check func
	for (int x = 0; x < W; x++) {
		int cnt = 0, tmp = 0;
		for (int y = 1; y < D; y++) {
			if (map[y][x] == map[y - 1][x]) {
				tmp++;
			}
			else tmp = 0;
			if (tmp > cnt) cnt = tmp;
		}
		if (cnt < K - 1) return false;
	}
	return true; 
}

void DFS(int now, int limit, int AB, int start) { // DFS search func

	if (now == limit) { // end condition
		for (int i = 0; i < D; i++) { // map change
			if (lineSaverA[i] == 1) {
				fill(&map[i][0], &map[i][W], 0);
			}
			if (lineSaverB[i] == 1) {
				fill(&map[i][0], &map[i][W], 1);
			}
		}

		if (isValid()) { // Be Valid
			if (now < minimum) minimum = now;
			flag = 1;
			return;
		}
		else { // Be not Valid
			BT(); // back tracking func call 
			return;
		}
	}

	for (int type = 0; type < 2; type++) {
		if (type == 0) { // A
			for (int i = start; i < D; i++) {
				lineSaverA[i] = 1;
				DFS(now + 1, limit, type, i + 1);
				lineSaverA[i] = 0;
				if (flag == 1) return;
			}
		}
		else { // type == 1 // B
			for (int i = start; i < D; i++) {
				lineSaverB[i] = 1;
				DFS(now + 1, limit, type, i + 1);
				lineSaverB[i] = 0;
				if (flag == 1) return;
			}
		}
	}

}

void solve() { // solved func
	if (isValid()) {
		minimum = 0;
		return;
	}
	else {
		for (int limit = 1; limit < D; limit++) {
			DFS(0, limit, -1, 0);
			if (flag == 1) return;
		}
	}
	return;
}

void init() { // initialization func
	D = W = K = flag = 0;
	minimum = 21e8;
	memset(map, 0, sizeof(map));
	memset(backup, 0, sizeof(backup));
	memset(lineSaverA, 0, sizeof(lineSaverA));
	memset(lineSaverB, 0, sizeof(lineSaverB));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init(); // init func call
		cin >> D >> W >> K;

		// input
		for (int y = 0; y < D; y++) {
			for (int x = 0; x < W; x++) {
				cin >> map[y][x];
			}
		}

		// backup (back tracking)
		copy(&map[0][0], &map[D][W], &backup[0][0]);

		// solve func call 
		solve();

		// result ...
		cout << "#" << tc + 1 << " " << minimum << "\n";
	}

	return 0;
}