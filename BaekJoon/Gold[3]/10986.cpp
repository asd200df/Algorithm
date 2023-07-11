// 나머지 합 (10986) Gold[3]
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
int N; // <= 1,000,000
int M; // <= 1,000
// 들어올 수 있는 값의 크기1,000,000,000


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
	vector<long long> vec(1001);
	long long target = 0;
	long long sum = 0;

	cin >> N >> M;
	
	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		sum += inp;
		vec[sum % M]++;
		if (sum % M == 0) { target++; }
	}
	
	for (int i = 0; i <= M; i++) {
		target += (vec[i] * (vec[i] - 1)) / 2;
	}

	cout << target << "\n";
}