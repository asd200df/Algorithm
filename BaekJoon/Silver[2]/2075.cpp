// N번째 큰 수 (2075) Silver[2]
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
int N;

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
		for (int j = 0; j < N; j++) {
			cin >> inp;
			pq.push(inp);
			if (pq.size() > N) { pq.pop(); }
		}
	}

	int result = pq.top();

	cout << result << "\n";
}