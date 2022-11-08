/* 쉬운 거스름돈
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

int Mlist[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
int dat[8] = { 0 };

void init() {
	memset(dat, 0, sizeof(dat));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		int money;
		cin >> money;

		for (int i = 0; i < 8; i++) {
			int tmp = money / Mlist[i];
			money = money % Mlist[i]; 
			dat[i] = tmp;
		}

		cout << "#" << tc + 1 << "\n";
		for (int i = 0; i < 8; i++) cout << dat[i] << " ";
		cout << "\n";
	}
	return 0;
}
*/