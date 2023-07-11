// 구간 합 구하기 (11659) Silver[3]
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
int N, M;

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

// input & solution
void insol() {
	cin >> N >> M;

	int arr[100002];
	int cumsum[100002];
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		cumsum[i] = cumsum[i - 1] + arr[i]; 
	}

	int or1 = 0;
	int or2 = 0;
	for (int i = 1; i <= M; i++) {
		cin >> or1 >> or2;
		cout << cumsum[or2] - cumsum[or1 - 1] << "\n";
	}

}
