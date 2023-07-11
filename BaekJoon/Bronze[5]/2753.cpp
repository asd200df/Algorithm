// À±³â (2753) Bronze[5]
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
int year;

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
	cin >> year;

	if (year % 4 == 0 && year % 100 != 0) { cout << "1\n"; }
	else if (year % 400 == 0) { cout << "1\n"; }
	else { cout << "0\n"; }
}
