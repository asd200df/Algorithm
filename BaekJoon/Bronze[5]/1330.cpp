// 두 수 비교하기 (1330) Bronze[5]
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
	cin >> A >> B;

	if (A > B) { cout << ">\n"; }
	else if (A < B) { cout << "<\n"; }
	else { cout << "==\n"; }
}
