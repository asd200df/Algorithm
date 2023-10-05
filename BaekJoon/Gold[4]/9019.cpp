// DSLR (9019) Gold[4]
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
int T;
typedef struct { 
	int num; 
	string path; 
}node;

// Function
void insolve();
string BFS(string st, string ed);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		insolve();
	}

	return 0;
}

// input && solution
void insolve() {
	string st, ed, result;
	cin >> st >> ed;

	result = BFS(st, ed);

	cout << result << "\n";
}

// Breadth-First Search
string BFS(string st, string ed) {
	bool used[10000];
	for (int i = 0; i < 10000; i++) { used[i] = false; }
	queue<node> que;
	que.push({ stoi(st), "" });
	used[stoi(st)] = true;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		// if (now.num < 0 || now.num > 9999) { continue; }

		if(to_string(now.num) == ed) { return now.path; }

		for (int i = 0; i < 4; i++) {
			int nn = now.num;
			string np = now.path;

			if (i == 0) { // D
				nn = (nn * 2) % 10000;
				np += "D";
				if (used[nn]) { continue; }
				used[nn] = true;
				que.push({ nn, np });
			}
			else if (i == 1) { // S
				nn = nn - 1;
				np += "S";
				if (nn < 0) { nn = 9999; }
				if (used[nn]) { continue; }
				used[nn] = true;
				que.push({ nn, np });
			}
			else if (i == 2) { // L
				nn = ((nn % 1000) * 10) + (nn / 1000);
				np += "L";
				if (used[nn]) { continue; }
				used[nn] = true;
				que.push({ nn, np });
			}
			else { // i == 3 // R
				nn = ((nn % 10) * 1000) + (nn / 10);
				np += "R";
				if (used[nn]) { continue; }
				used[nn] = true;
				que.push({ nn, np });
			}
		}
	}

	// int deubg = 0;
}