// 사분면 고르기 (14681) Bronze[5]
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
int y, x;

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
	cin >> x >> y;

	if (y > 0 && x > 0) { cout << "1\n"; }
	else if (y > 0 && x < 0) { cout << "2\n"; }
	else if (y < 0 && x < 0) { cout << "3\n"; }
	else if (y < 0 && x > 0) { cout << "4\n"; }
}
