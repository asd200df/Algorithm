// ¹®ÀÚ¿­ (9086) Bronze[5]
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
int T;

// Function
void insol();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		insol();
	}

	return 0;
}

// input && solution
void insol() {
	string inp;

	cin >> inp;

	cout << inp[0] << inp[inp.size() - 1] << "\n";
}