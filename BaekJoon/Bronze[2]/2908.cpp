// »ó¼ö (2908) Bronze[2]
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
// -

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
	string inp1, inp2;
	string trans1, trans2;
	int num1, num2, maxi = -21e8;

	cin >> inp1 >> inp2;

	for (int i = inp1.size() - 1; i >= 0; i--) { trans1 += inp1[i]; }
	for (int i = inp2.size() - 1; i >= 0; i--) { trans2 += inp2[i]; }

	num1 = stoi(trans1);
	num2 = stoi(trans2);

	maxi = max(num1, num2);

	cout << maxi << "\n";
}