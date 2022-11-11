// 장훈이의 높은 선반 
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

int N, B, H[21], minimum = 21e8;

void DFS(int uni, int start) { // DFS search func 
	if (uni >= B) { 
		if (minimum > uni) minimum = uni;
		return;
	}
	for (int i = start; i < N; i++) {
		DFS(uni + H[i], i + 1);
	}
}

void init() { // initialization func
	N = B = 0;
	memset(H, 0, sizeof(H));
	minimum = 21e8;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init(); // init func call
		// input
		cin >> N >> B;
		for (int i = 0; i < N; i++) { cin >> H[i]; }

		DFS(0, 0); // DFS func call

		int result = minimum - B;

		cout << "#" << tc + 1 << " " << result << "\n";
	}

	return 0;
}