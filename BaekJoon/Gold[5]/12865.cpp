// Æò¹üÇÑ ¹è³¶ (12865) Gold[5]
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
int N, K;
int W[101], V[101];
int DP[105][100005];

// Function
void input();
void solve();
int NS();

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
	cin >> N >> K;
	for (int i = 1; i <= N; i++) { cin >> W[i] >> V[i]; }
}

// solution
void solve() {
	int maxi = -21e8;

	maxi = NS();

	cout << maxi << "\n";
}

// knapsack algorithm
int NS() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {

			if (j - W[i] >= 0) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
			else DP[i][j] = DP[i - 1][j];
		}
	}
	int debug = 0;
	return DP[N][K];
}