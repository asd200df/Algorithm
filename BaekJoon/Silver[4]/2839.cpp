// º≥≈¡ πË¥ﬁ (2839) Silver[4]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N, result = -1; // <= 5000

// Function
void input();
void solve();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N;
}

// solution
void solve() {
	int bag = 0;
	
	while (N > 0) {

		if ((N % 5) == 0) {
			bag += N / 5;
			N = N % 5;
		}
		else {
			N -= 3;
			bag++;
		}

		if (N == 0){ // Find
			cout << bag << "\n";
			return;
		}
	}

	// Not Found
	cout << "-1\n";
}
