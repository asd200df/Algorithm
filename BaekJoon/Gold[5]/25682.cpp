// 체스판 다시 칠하기 2 (25682) Gold[5]
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
int N, M; // <= 2000
int K; // <= min(N,M)
int W_dif[2005][2005]; // W & B different cumulative sum 1
int B_dif[2005][2005]; // 2

// Function
void insol();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N >> M >> K;
	
	char inp;
	int temp = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> inp;

			if (((i + j) % 2) == 0) {
				if (inp == 'W') { 
					W_dif[i][j] = (W_dif[i - 1][j] + W_dif[i][j - 1]) - W_dif[i - 1][j - 1];
					B_dif[i][j] = 1 + ((B_dif[i - 1][j] + B_dif[i][j - 1]) - B_dif[i - 1][j - 1]);
				}
				else {
					W_dif[i][j] = 1 + ((W_dif[i - 1][j] + W_dif[i][j - 1]) - W_dif[i - 1][j - 1]);
					B_dif[i][j] = (B_dif[i - 1][j] + B_dif[i][j - 1]) - B_dif[i - 1][j - 1];
				}
			}
			else {
				if (inp == 'B') {
					W_dif[i][j] = (W_dif[i - 1][j] + W_dif[i][j - 1]) - W_dif[i - 1][j - 1];
					B_dif[i][j] = 1 + ((B_dif[i - 1][j] + B_dif[i][j - 1]) - B_dif[i - 1][j - 1]);
				}
				else{
					W_dif[i][j] = 1 + ((W_dif[i - 1][j] + W_dif[i][j - 1]) - W_dif[i - 1][j - 1]);
					B_dif[i][j] = (B_dif[i - 1][j] + B_dif[i][j - 1]) - B_dif[i - 1][j - 1];
				}
			} 
		}

		if (i == N) { // debug 용
			int debug = 0;
		}
	}

	int minimum = 21e8;
	for (int i = K; i <= N; i++) {
		for (int j = K; j <= M; j++) {
			int w_target = (W_dif[i][j] - (W_dif[i - K][j] + W_dif[i][j - K])) + W_dif[i - K][j - K];
			int b_target = (B_dif[i][j] - (B_dif[i - K][j] + B_dif[i][j - K])) + B_dif[i - K][j - K];

			minimum = min(w_target, minimum);
			minimum = min(b_target, minimum);
		}
	}

	cout << minimum << "\n";
}