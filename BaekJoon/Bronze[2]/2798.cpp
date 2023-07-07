// ∫Ì∑¢¿Ë (2798) Bronze[2]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N, M, maxi = -21e8;
int card[101];

// Function
void input();
void solve();
void DFS(int now, int sum);

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
	cin >> N >> M;
	for (int i = 0; i < N; i++) { cin >> card[i]; }
}

// solution
void solve() {

	DFS(0, 0);

	cout << maxi << "\n";
}

// Depth-First Search
int used[101];
void DFS(int now, int sum) {
	if (now == 3) {
		if (sum > M) { return; }
		if (sum > maxi) { maxi = sum; }
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 1) { continue; }

		used[i] = 1;
		DFS(now + 1, sum + card[i]);
		used[i] = 0;
	}
}