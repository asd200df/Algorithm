// queuestack (24511) Silver[3]
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
int M; // <= 100,000
int type[100005]; // queue or stack
stack<int> st;
queue<int> que;

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
	cin >> N;
	
	for (int i = 0; i < N; i++) { cin >> type[i]; }
	
	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		if (type[i]) { continue; } // 스택이면 넣을 필요 없음
		st.push(inp);
	} 
}

// solution
void solve() {
	cin >> M;

	int inp;
	for (int i = 0; i < M; i++) {
		cin >> inp;
		que.push(inp);
	}

	int cnt = 0;
	while (true) {
		if (cnt == M) { break; }

		if (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		else {
			cout << que.front() << " ";
			que.pop();
		}

		cnt++;
	}

	cout << "\n";
}