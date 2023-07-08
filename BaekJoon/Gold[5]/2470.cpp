// 두 용액 (2470) Gold[5]
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
int N;	// <= 100,000	//	-10억 ~ 10억까지 들어옴
long long arr[100001];

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
	for (int i = 0; i < N; i++) { cin >> arr[i]; }
}

// solution
void solve() {
	long long result[2] = { 0 };
	int left = 0;
	int right = N - 1;
	long long mini = 21e8;

	sort(arr, arr + N);

	// valid check
	while (left != right) {
		long long target = arr[left] + arr[right];

		if (mini > abs(target)) { // minimum update
			mini = abs(target);
			result[0] = arr[left];
			result[1] = arr[right];
		}

		if (target == 0) { // find
			result[0] = arr[left];
			result[1] = arr[right];
			break;
		}
		else if (target < 0){ left++; }
 		else { right--; } // target > 0
	}

	// result
	for (int i = 0; i < 2; i++) { cout << result[i] << " "; }
	cout << "\n";
}