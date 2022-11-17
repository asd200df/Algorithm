/* ½Ã°¢ µ¡¼À
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
		int h1, m1, h2, m2, rh, rm;
		cin >> h1 >> m1 >> h2 >> m2;

		// hour
		if ((h1 + h2) > 12) { rh = (h1 + h2) - 12; }
		else rh = h1 + h2;

		// min
		int tmp = 0;
		if((m1 + m2) > 59) { 
			tmp = (m1 + m2) / 60;
			rm = (m1 + m2) % 60;
			rh += tmp;
		}
		else rm = m1 + m2;

		cout << "#" << tc + 1 << " " << rh << " " << rm << "\n";
	}

	return 0;
}
*/