// ÃÖ´ë Èü (11279) Silver[2]
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

// Function
void input();
void solve();

// Main
int main(int argc, char** argv) {
	FastIO;

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N;
}

// solution
void solve() {

	priority_queue<int> pq;
	int inp = 0;
	int out = 0;
	for (int i = 0; i < N; i++) {
		cin >> inp;

		if (inp != 0) {
			pq.push(inp);
		}
		else {
			if (pq.empty()) {
				cout << "0\n";
				continue;
			}

			out = pq.top();
			pq.pop();
			cout << out << "\n";
		}

	}

}