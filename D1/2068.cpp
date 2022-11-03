// 최대수 구하기
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
// #include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int num[11], Max = -21e8;

		for (int i = 0; i < 10; i++) { 
			cin >> num[i];
			if (Max < num[i]) Max = num[i];
		}

		cout << "#" << tc + 1 << " " << Max << "\n";
	}

	return 0;
}