// A+B
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
int num1, num2;

// Function
void init();
void input();

// MAIN
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		input();
		cout << "Case #" << tc + 1 << ": " << num1 + num2 << "\n";
	}

	return 0;
}

// initialization
void init() {
	num1 = num2 = 0;
}

// input
void input() {
	cin >> num1 >> num2;
}