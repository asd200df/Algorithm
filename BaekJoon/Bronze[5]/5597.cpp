// 과제 안 내신 분..? (5597) Bronze[5]
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

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int arr[31];

// Function
void insol();

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input && solution
void insol() {

	int inp = 0;
	for (int i = 0; i < 28; i++) {
		cin >> inp;
		arr[inp] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		if (arr[i] == 1) { continue; }
		cout << i << "\n";
	}
}