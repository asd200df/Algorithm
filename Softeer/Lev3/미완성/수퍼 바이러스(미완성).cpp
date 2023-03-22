// 수퍼 바이러스
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
long long K, P, N;

// Function
void input();
int solve();

// main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = 0;

	input();
	result = solve();

	cout << result << "\n";

	return 0;
}

// input
void input() {
	cin >> K >> P >> N;
}

// solution
int solve() {
	long long sum = K, tmp = 0;

	for (long long i = 0; i < (N * 10); i++) {
		sum = sum * P;
		sum = sum % 1000000007;
	}

	return sum;
}