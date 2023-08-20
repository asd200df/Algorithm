// 스타트링크 (5014) Silver[1]
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
int F, S, G, U, D; // N <= 1,000,000
int used[1000001];
typedef struct {
	int floor, cnt;
}node;

// Function
void input();
void solve();
int BFS();

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
void input() { cin >> F >> S >> G >> U >> D; }

// solution
void solve() {
	string result;

	// Exception
	if(S == G) { 
		cout << "0\n";
		return;
	}

	// BFS func call
	int tmp = BFS();
	
	// result update
	if (tmp == -1) { result = "use the stairs\n"; }
	else { result = to_string(tmp); }

	// print result
	cout << result << "\n";
}

// Breadth-First Search
int BFS() {
	queue<node> que;
	que.push({ S, 0 });
	used[S] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int type = 1; type <= 2; type++) {
			int nc = now.cnt + 1;
			
			if (type == 1 && U != 0) { // up
				int up = now.floor + U;

				if (F < up) { continue; }
				if (used[up] == 1) { continue; }
				used[up] = 1;

				if (G == up) { return nc; }

				que.push({ up, nc });
			}
			else if (type == 2 && D != 0) { // down
				int dn = now.floor - D;

				if (dn < 1) { continue; }
				if (used[dn] == 1) { continue; }
				used[dn] = 1;

				if (G == dn) { return nc; }

				que.push({ dn, nc });
			}
		}
	}

	return -1;
}