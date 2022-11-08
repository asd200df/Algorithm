// 수도 요금 경쟁
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

// global
int P, Q, R, S, W;

int Acompany() { // A company fee func
	return P * W;
}

int Bcompany() { // B company fee func
	if (W < R) return Q;
	else return Q + ((W - R) * S);
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
		cin >> P >> Q >> R >> S >> W;

		// print inexpensive !
		int A, B;
		A = Acompany();
		B = Bcompany();
		// if B company is inexpensive more than A company
		if (A > B) cout << "#" << tc + 1 << " "
			<< B << "\n";
		// else 
		else cout << "#" << tc + 1 << " " << A << "\n";
	}

	return 0;
}