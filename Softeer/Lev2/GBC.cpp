// GBC
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N, M;
int whole;
int standard[101], custom[101];

// Function
void input();
int solve();

// MAIN
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	int result = solve();

	cout << result << "\n";

	return 0;
}

// input
void input() {
	int whole2 = 0;

	cin >> N >> M;

	int previous = 0;
	for (int i = 0; i < N; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		previous = whole + 1;
		whole += tmp1;
		for (int k = previous; k <= whole; k++) {
			standard[k] = tmp2;
		}
	}

	previous = 0;
	for (int i = 0; i < M; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		previous = whole2 + 1;
		whole2 += tmp1;
		for (int k = previous; k <= whole2; k++) {
			custom[k] = tmp2;
		}
	}

	if (whole2 > whole) whole = whole2;
}

// solution
int solve() {
	int maxi = -21e8, tmp = 0;

	for (int i = 1; i <= whole; i++) {
		if (standard[i] < custom[i]) tmp = custom[i] - standard[i];

		if (maxi < tmp) maxi = tmp;
	}

	if (maxi <= 0) return 0;
	return maxi;
}