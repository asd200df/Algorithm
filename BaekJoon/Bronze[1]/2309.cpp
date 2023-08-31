// ¿œ∞ˆ ≥≠¿Ô¿Ã (2309) Bronze[1]
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
int dwarf[10], pick[10];
int used[9];
bool flag = false;

// Function
void insol();
void DFS(int now, int sum);

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

	for (int i = 0; i < 9; i++) { cin >> dwarf[i]; }

	DFS(0, 0);

	sort(pick, pick + 7);

	for (int i = 0; i < 7; i++) { cout << pick[i] << " "; }
	cout << "\n";
}

// Depth-First Search
void DFS(int now, int sum) {
	if (flag) { return; }

	if (now == 7) {
		if (sum == 100) { flag = true; }
		return;
	}

	for (int i = 0; i < 9; i++) {
		int next = dwarf[i];

		if (used[i] == 1) { continue; }

		used[i] = 1;
		pick[now] = next;
		DFS(now + 1, sum + next);
		if (flag) { break; }
		used[i] = 0;
	}
}