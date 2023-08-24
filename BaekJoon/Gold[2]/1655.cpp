// 가운데를 말해요 (1655) Gold[2]
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
void insol();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N;

	// initialization
	priority_queue<int> DESC;
	priority_queue<int, vector<int>, greater<int>> ASC;

	// input & solve
	int inp, Dsize, Asize, Dtop, Atop;
	for (int i = 1; i <= N; i++) {
		cin >> inp;

		Dsize = DESC.size();
		Asize = ASC.size();

		// rule 1
		if (Dsize <= Asize) { DESC.push(inp); }
		else { ASC.push(inp); }

		Dtop = DESC.top();
		if (!ASC.empty()) {
			Atop = ASC.top();

			// rule 2
			if (Dtop > Atop) {
				DESC.pop();
				ASC.pop();
				DESC.push(Atop);
				ASC.push(Dtop);
			}
		}

		// result !
		cout << DESC.top() << "\n";
	}

	// int debug = 0;
	// debug++;

}