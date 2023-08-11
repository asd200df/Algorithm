/* 나무 높이
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int tree[101], max_tree, N, day = 0;

void func() {

	while (1) {
		day++;

		if (day % 2 == 1) {  // odd day

		}
		else {  // even day

		}

	}

	return;
}

void init() { // initialization func

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			cin >> tree[i];
			max_tree = max(max_tree, tree[i]);
		}

		func();

		// cout << "#" << tc + 1 << " " << ... << endl;
	}

	return 0;
}

*/