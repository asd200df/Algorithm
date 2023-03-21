// 바이러스 
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
int K, P, N;

// Function
void input();
int solve();

// MAIN
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	int result = solve();

	cout << result << "\n";

	return 0;
}

// input
void input() {
	cin >> K >> P >> N;
}

// solution
int solve() {
	unsigned long long int tmp = 0, sum = K;

	for (int i = 0; i < N; i++) {
		sum = (sum * P) % 1000000007;
	}

	return sum;
}