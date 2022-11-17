/* 숫자를 정렬하자
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
		int n, num[51];
		cin >> n;
		for (int i = 0; i < n; i++) { cin >> num[i]; }
		sort(num, num + n);

		cout << "#" << tc + 1 << " ";
		for (int i = 0; i < n; i++) { cout << num[i] << " "; }
		cout << "\n";
	}

	return 0;
}
*/