// 좋다 (1253) Gold[4]
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
int N; // <= 2,000 // 수 크기 <= 1,000,000,000
long long arr[2001];

// Function
void input();
void solve();
bool BS(int ins);

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

	int cnt = 0;
	for (int i = 0; i < N; i++) { 
		if (BS(i)) { cnt++; }
	}

	cout << cnt << "\n";
}

// Binary Search
bool BS(int ins) {
	long long target = arr[ins];

	int left = 0;
	int right = N - 1;
	while (left < right) {
		long long now = arr[left] + arr[right];

		if (left == ins) { 
			left++; 
			continue;
		}
		else if (right == ins) { 
			right--; 
			continue;
		}

		// int deubg = 0;

		if (now == target) { return true; }

		else {
			if (now < target) { left++; }
			else { right--; } // now > target
		}
	}

	return false;
}