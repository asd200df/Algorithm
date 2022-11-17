// Å« ³ð, ÀÛÀº ³ð, °°Àº ³ð
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int a, b;
		cin >> a >> b;

		if(a > b){ cout << "#" << tc + 1 << " >\n"; }
		else if(a < b){ cout << "#" << tc + 1 << " <\n"; }
		else cout << "#" << tc + 1 << " =\n";
	}

	return 0;
}