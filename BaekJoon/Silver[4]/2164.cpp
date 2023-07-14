// Ä«µå2 (2164) Silver[4]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int N; // <= 500,000

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
	cin >> N;

	int result = 0;
	queue<int> que;
	
	for (int i = 1; i <= N; i++) { que.push(i); }

	while (!que.empty()) {
		if (que.size() == 1) {
			result = que.front();
			break;
		}

		que.pop();
		int temp = que.front();
		que.pop();
		que.push(temp);
	}

	cout << result << "\n";
}