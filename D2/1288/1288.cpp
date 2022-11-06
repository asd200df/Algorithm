// 새로운 불면증 치료법
#include <iostream>
#include <string>
#include <cstring>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>
// #include <algorithm>
// #include <unordered_map>

using namespace std;

// global
int num, N, used[10], ret = 0;

void parsing(int N) { // parsing function
	string n = to_string(N);

	for (int i = 0; i < n.length(); i++) {
		int tmp = n[i] - '0';
		used[tmp] = 1;
	}
}

void init() { // initialization function
	num = 0;
	N = 0;
	memset(used, 0, sizeof(int) * 10);
	ret = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) { // test case
		init(); // init func call
		cin >> num;
		N = num;

		while (1) { // run

			ret++; // count

			parsing(N); // parsing func call
			
			int cnt = 0;
			for (int i = 0; i < 10; i++) { // check
				if (used[i] == 1) cnt++;
			} if (cnt == 10) break;

			N += num; // add
		}
		cout << "#" << tc + 1 << " " << N << "\n";
	}

	return 0;
}