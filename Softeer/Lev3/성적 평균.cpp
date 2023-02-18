/* 己利 乞闭 - 205ms
#include<iostream>
// #include<stdio.h>
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
int N, K;
int S[1000000];

// Function
void input();
double solve();

// main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double result = 0;

	input();

	for (int tc = 0; tc < K; tc++) {
		result = solve();
		printf("%.2f \n", result);
	}

	return 0;
}

// input
void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
}

// solution
double solve() {
	int first, last;
	double sum;
	cin >> first >> last;

	for (int i = first - 1; i < last; i++) { sum += S[i]; }

	return sum / ((last - first) + 1);
}
*/

// 规过2 (prefix sum) - 65ms
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
int N, K;
int S[1000001];
int prefix[1000001];

// Function
void input();
void solve();

// main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	for (int i = 0; i < K; i++) { solve(); }

	return 0;
}

// input
void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
		prefix[i] = prefix[i - 1] + S[i];
	}
}

// solution
void solve() {
	int first, last;
	double tmp;
	cin >> first >> last;

	tmp = prefix[last] - prefix[first - 1];

	printf("%.2f \n", tmp / (last - first + 1));
}