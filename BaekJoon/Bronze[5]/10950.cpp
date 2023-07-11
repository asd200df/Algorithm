// A+B-3 (10950) Bronze[5]
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
int T;

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
	cin >> T;

	int n1 = 0;
	int n2 = 0;
	for (int tc = 0; tc < T; tc++) {
		cin >> n1 >> n2;
		cout << n1 + n2 << "\n";
	}
}
