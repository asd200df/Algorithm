// 스마트 물류
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
char rail[20001];
int based[20001];

// Function
void input();
int solve();
bool isValid(int idx);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	int result = solve();

	cout << result;

	return 0;
}

// input
void input() {
	cin >> N >> K;
	cin >> rail;
	for (int i = 0; i < N; i++) { if (rail[i] == 'P') { based[i] = 1; } }
}

// solve
int solve() {
	int cnt = 0;

	// check
	for (int i = 0; i < N; i++) {
		if (based[i] == 0 || based[i] == 2 || based[i] == 3) continue;
		if (isValid(i)) { based[i] = 3; }
	}

	// count
	for (int i = 0; i < N; i++) {
		// cout << based[i] << " "; // For debug
		if (based[i] == 2) cnt++;
	}

	return cnt;
}

// valid check
bool isValid(int idx) {

	for (int i = idx - K; i <= idx + K; i++) {
		if (i < 0 || i >= N) continue;
		if (based[i] == 0) {
			based[i] = 2;
			return true;
		}
	}

	return false;
}

/*
	for debug
	for(int i = 0; i < N; i++) cout << rail[i] << " ";
	cout << endl;
*/