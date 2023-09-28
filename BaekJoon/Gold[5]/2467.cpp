// 용액 (2467) Gold[5]
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
int N; // 2 <= 100,000
int arr[100005];
int ret[2];
// -1,000,000,000 <= 범위 <= 1,000,000,000 

// Function
void input();
void solve();
void BS();

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

	sort(arr, arr + N);

	BS();

	sort(ret, ret + 2);
	cout << ret[0] << " " << ret[1] << "\n";
}

// Binary Search
void BS() {
	int mini = 21e8;

	int left = 0;
	int right = N - 1;
	while (left < right) {
		long long now = arr[left] + arr[right];

		if (now == 0) {
			ret[0] = arr[left];
			ret[1] = arr[right];
			return;
		}
		else if (abs(now) < mini) {
			mini = abs(now);
			ret[0] = arr[left];
			ret[1] = arr[right];
		}

		if (now < 0) { left++; }
		else { right--; }
		
	}

}