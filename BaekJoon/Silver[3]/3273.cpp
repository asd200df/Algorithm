// 두 수의 합 (3273) Silver[3]
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
int N, target;
int arr[1000001];

// Function
void input();
void solve();
int TP();

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
	cin >> target;
}

// solve
void solve() {
	int result = 0;

	sort(arr, arr + N);

	result = TP();

	cout << result << "\n";
}

// Two-Pointer
int TP() {
	int cnt = 0;
	int left = 0;
	int right = N - 1;

	while (left < right) {
		int temp = arr[left] + arr[right];

		if (temp == target) {
			cnt++;
			left++;
			right--;
		}
		else if (temp > target) { right--; }
		else if (temp < target) { left++; }

	}

	return cnt;
}