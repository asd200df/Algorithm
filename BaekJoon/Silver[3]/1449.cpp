// ¼ö¸®°ø Ç×½Â (1449) Silver[3]
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
int N, L;
int pipe[1005];

// Function
void input();
void solve();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N >> L;

	for (int i = 0; i < N; i++) { cin >> pipe[i]; }
}

// solution
void solve() {
	int cnt = 0;

	sort(pipe, pipe + N);

	int tape = L;
	int pre = pipe[0];
	for (int i = 0; i < N; i++) {
		int diff = pipe[i] - pre;
		
		if (tape <= diff) {
			cnt++;

			pre = pipe[i];
		}
	}

	if (N != 0) { cout << cnt + 1 << "\n"; }
	else { cout << "0\n"; }
}