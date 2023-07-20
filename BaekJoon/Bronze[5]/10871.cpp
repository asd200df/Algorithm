// X보다 작은 수 (10871) Bronze[5]
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
int N, X;

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
	cin >> N >> X;

	int target = 0;
	for (int i = 0; i < N; i++) {
		cin >> target;
		if (target < X) { cout << target << " "; }
	} cout << "\n";
}