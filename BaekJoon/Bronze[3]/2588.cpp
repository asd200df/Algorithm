// °ö¼À (2588) Bronze[3]
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
int A, B;

// Function
void input();
void solve();

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
	cin >> A >> B;
}

// solution
void solve() {
	int C = A * B;

	while (B > 0) {
		int temp = B % 10;
		B = B / 10;

		cout << A * temp << "\n";
	}

	cout << C << "\n";
}