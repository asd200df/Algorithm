// 커트라인 (25305) Bronze[2]
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
int N, K; // N <= 1000
int arr[1001];

// Function
void insol();

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) { cin >> arr[i]; }

	sort(arr, arr + N, greater<int>());

	cout << arr[K - 1] << "\n";
}