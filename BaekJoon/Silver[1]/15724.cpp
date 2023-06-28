// ÁÖÁö¼ö (15724) Silver[1]
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
int N, M, K;
int ego, lft, up, re; // cal
int now_y1, now_x1, now_y2, now_x2; //cumsum
int arr[1030][1030];
int cumsum[1030][1030];
typedef struct {
	int y1, x1;
	int y2, x2;
}node;
node karr[100001];

// Function
void input();
void solve();
void cal();
int CS(int idx);

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
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	
	cin >> K;
	int tmp1, tmp2, tmp3, tmp4;
	for(int i = 0; i < K; i++) { 
		cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
		karr[i] = { tmp1, tmp2, tmp3, tmp4 };
	}
}

// solve
void solve() {
	int result = 0;

	// Calculator & Cumulative sum
	cal();

	// result cout !
	for (int i = 0; i < K; i++) {
		result = CS(i);
		cout << result << "\n";
	}
}

// Calculator
void cal() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ego = arr[i][j];
			lft = cumsum[i][j - 1];
			up = cumsum[i - 1][j];
			re = cumsum[i - 1][j - 1];

			cumsum[i][j] = (ego + lft + up) - re;
		}
	}
}

// Cumulative Sum
int CS(int idx) {
	int sum = 0;
	
	now_y1 = karr[idx].y1;
	now_x1 = karr[idx].x1;
	now_y2 = karr[idx].y2;
	now_x2 = karr[idx].x2;

	ego = cumsum[now_y2][now_x2];
	lft = cumsum[now_y2][now_x1 - 1];
	up = cumsum[now_y1 - 1][now_x2];
	re = cumsum[now_y1 - 1][now_x1 - 1];

	sum = (ego - lft - up) + re;

	return sum;
}