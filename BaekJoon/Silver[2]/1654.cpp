// 랜선 자르기 (1654) Silver[2]
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

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int K, N; // K <= 10,000 // N <= 1,000,000
int lan[10001];
int big = -21e8;

// Function
void input();
void solve();

// Main
int main(int argc, char** argv) {
	FastIO;

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) { 
		cin >> lan[i]; 
		big = max(big, lan[i]);
	}
	int debug = 0;
}

// solution
void solve() {
	long long maxi = -21e8;

	// sort ASC
	sort(lan, lan + K);

	// Binary Search
	long long left = 1;
	long long right = big;
	long long mid, target, idx;
	while (left <= right) {
		mid = (left + right) / 2;
		target = 0;

		// lower_bound
		idx = lower_bound(lan, lan + K, mid) - lan;
		
		for (int i = idx; i < K; i++) {
			target += lan[i] / mid;
		}

		if (target >= N) {
			maxi = max(maxi, mid);
			left = mid + 1;
		}
		else { // target < N
			right = mid - 1;
		}

	}

	cout << maxi << "\n";
}