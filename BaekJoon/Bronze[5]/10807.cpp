// 개수 세기 (10807) Bronze[5]
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
int N;
int arr[2][102];

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
	int target = 0;

	cin >> N;

	int idx = 0;
	for (int i = 0; i < N; i++) {
		cin >> idx;
		if (idx < 0) { arr[0][idx * -1]++; }
		else { arr[1][idx]++; } 
	}

	cin >> target;

	if (target < 0) { cout << arr[0][target * -1] << "\n"; }
	else { cout << arr[1][target] << "\n"; }
}