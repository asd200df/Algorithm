// 입국심사 (3079) Gold[5]
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
long long N; // 1 <= 100,000
long long M; // 1 <= 1,000,000,000
long long stand[100005]; // (1 ≤ Tk ≤ 1,000,000,000)

// Function
void input();
void solve();
long long BS();

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
	cin >> N >> M;
	for (int i = 0; i < N; i++) { cin >> stand[i]; }
}

// solution
void solve() {
	long long result = 0;

	/* if (N == 1) { // 심사대가 1개일 때 
		cout << stand[0] * M << "\n"; 
		return;
	} */

	sort(stand, stand + N);

	result = BS();

	cout << result << "\n";
}

// Binary Search
long long BS() {
	long long mini = 0;

	long long left = 1;
	long long right = M * stand[0]; // 최솟값에 * 인구수
	while (left <= right) {
		long long mid = (left + right) / 2;

		long long sum = 0;
		for (int i = 0; i < N; i++) { sum += mid / stand[i]; }

		if (sum < M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			mini = mid;
		}

	}

	// int debug= 0;
	
	return mini;
}