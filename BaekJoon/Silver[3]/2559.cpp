// ¼ö¿­ (2559) Silver[3]
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
int N, K;

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
	cin >> N >> K;

	int arr[100002];
	int cumsum[100002];
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		cumsum[i] = cumsum[i - 1] + arr[i]; 
	}

	int maxi = -21e8;
	for (int i = K; i <= N; i++) {
		maxi = max(maxi, cumsum[i] - cumsum[i - K]);
	}

	cout << maxi << "\n";
}
