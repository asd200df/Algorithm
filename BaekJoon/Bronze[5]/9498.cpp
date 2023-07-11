// 시험 성적 (9498) Bronze[5]
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
int grade;

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
	cin >> grade;

	if (90 <= grade && grade <= 100) { cout << "A\n"; }
	else if (80 <= grade && grade <= 89) { cout << "B\n"; }
	else if (70 <= grade && grade <= 79) { cout << "C\n"; }
	else if (60 <= grade && grade <= 69) { cout << "D\n"; }
	else { cout << "F\n"; }
}
