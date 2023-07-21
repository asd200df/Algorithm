// K번째 수 (1300) Gold[2]
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
int N, K;

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
	cin >> N >> K;
}

// solution
void solve() {
	int result = 0;

	int left = 1;
	int right = K; // 찾으려는 수까지만 searching 하면 되는건가 ? 
	int mid, cnt;
	while (left <= right) {
		mid = (left + right) / 2;
		
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}

		if (cnt < K) { 
			left = mid + 1;
		}
		else { // cnt >= K
			result = mid;
			right = mid - 1;
		}
	}

	cout << result << "\n";
}
