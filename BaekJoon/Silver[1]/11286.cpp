// Àý´ñ°ª Èü (11286) Silver[1]
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

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int x = 0;
	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x != 0) {
			pq.push({ abs(x), x });
		}
		else {
			if (!pq.empty()) {
				cout << pq.top().second << "\n";
				pq.pop();
			}
			else { cout << "0\n"; }
		}
	}
}