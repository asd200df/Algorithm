// 숫자의 합 (11720) Bronze[4]
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

using namespace std;

// Global
int N;

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
	cin >> N;

	int sum = 0;
	char n[101];

	for (int i = 0; i < N; i++) {
		cin >> n[i];
		sum += n[i] - '0';
	}

	cout << sum << "\n";
}