/* 간단한 369게임
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

	int N, tmp1, tmp2, cnt;
	string str;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		str = to_string(i);

		cnt = 0;
		if (str.find("3") != -1 || 
			str.find("6") != -1 || 
			str.find("9") != -1) {

			tmp1 = i;

			while (tmp1 != 0) {
				tmp2 = tmp1 % 10;
				tmp1 = tmp1 / 10;
				if (tmp2 == 3 || tmp2 == 6 || tmp2 == 9) cnt++;
			}


			for (int i = 0; i < cnt; i++) cout << "-";
			cout << " ";
			continue;
		}
		cout << i << " ";
	}

	return 0;
}
*/