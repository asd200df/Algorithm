// 카드 정렬하기 (1715) Gold[4]
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
int N; // <= 100,000

// Function
void insolve();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insolve();

	return 0;
}

// input && solution
void insolve() {
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	
	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		pq.push(inp);
	}

	int deubg = 0;

	if (N == 1) { // Exception
		cout << "0\n";
		return;
	}

	int sum = 0;
	while (!pq.empty()) {
		int next = 0;

		for (int i = 1; i <= 2; i++) {
			if (pq.empty()) { break; }
			int now = pq.top();
			pq.pop();
			next += now;
		}

		pq.push(next);
		sum += next;
		if (pq.size() == 1) { break; }
	}

	cout << sum << "\n";
}