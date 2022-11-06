// 지그재그 숫자
#include <iostream>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <cmath>
// #include <algorithm>
// #include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int N, ret = 0;
		cin >> N;

		for (int i = 1; i <= N; i++) {
			if ((i % 2) == 1) ret += i;
			else ret -= i;
		}
		cout << "#" << tc + 1 << " " << ret << "\n";
	}

	return 0;
}
