// 떡장수와 호랑이 (16432) Gold[4]
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
int N; // 1,000
bool flag = false;
bool used[1005][15];
int kind[1005];
int result[1005];
// int date[1005];
vector<vector<int>> tt(1005);

// Function
void input();
void solve();
void DFS(int now);

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
	cin >> N;
	
	int d, t;
	for (int i = 0; i < N; i++) {
		cin >> d;
		for (int j = 0; j < d; j++) {
			cin >> t;
			tt[i].push_back(t);
		}
	}
}

// solution
void solve() {

	DFS(0);

	if (flag) { for (int i = 0; i < N; i++) { cout << result[i] << "\n"; } }
	else { cout << "-1\n"; }
}

// Depth-First Search
void DFS(int now) {
	if (flag) { return; }

	if (now == N) {
		flag = true;
		for (int i = 0; i < N; i++) { result[i] = kind[i]; }
		return;
	}

	for (int i = 0; i < tt[now].size(); i++) {
		int nn = tt[now][i];

		if (now != 0) { // 전날이랑 중복
			if (kind[now - 1] == nn) { continue; }
		}
		if (used[now + 1][nn]) { continue; }

		used[now + 1][nn] = true;
		kind[now] = nn;
		DFS(now + 1);
		// 밑에 코드들이 TL(시간초과) 유발
		// kind[now] = -1;
		// used[now + 1][nn] = false;
	}
}