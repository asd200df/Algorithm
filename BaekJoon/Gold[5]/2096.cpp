// 내려가기 (2096) Gold[5]
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N; // <= 100,000
int maxi_DP[3];
int mini_DP[3];

// Function
void insol();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insol();

	return 0;
}

// input && solution
void insol() {
	int maxi = -21e8;
	int mini = 21e8;

	cin >> N;

	// dynamic programing
	int inp[3];
	int mx_tmp[3], mn_tmp[3];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) { cin >> inp[j]; }

		if (i == 0) { // first value
			for (int k = 0; k < 3; k++) {
				maxi_DP[k] = inp[k];
				mini_DP[k] = inp[k];
			}
			continue;
		}

		mx_tmp[0] = inp[0] + max(maxi_DP[0], maxi_DP[1]);
		mn_tmp[0] = inp[0] + min(mini_DP[0], mini_DP[1]);

		mx_tmp[1] = inp[1] + max({ maxi_DP[0], maxi_DP[1], maxi_DP[2]});
		mn_tmp[1] = inp[1] + min({ mini_DP[0], mini_DP[1], mini_DP[2]});

		mx_tmp[2] = inp[2] + max(maxi_DP[1], maxi_DP[2]);
		mn_tmp[2] = inp[2] + min(mini_DP[1], mini_DP[2]);
		
		int debug = 0;

		for (int l = 0; l < 3; l++) {
			maxi_DP[l] = mx_tmp[l];
			mini_DP[l] = mn_tmp[l];
		}
	}

	maxi = max({ maxi_DP[0], maxi_DP[1], maxi_DP[2] });
	mini = min({ mini_DP[0], mini_DP[1], mini_DP[2] });

	cout << maxi << " " << mini << "\n";
}