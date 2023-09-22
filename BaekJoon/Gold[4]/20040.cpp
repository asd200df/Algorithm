// 사이클 게임 (20040) Gold[4]
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
int N, M; //  <= 500,000 , <= 1,000,000
int parent[500001];

// Function
void insol();
int GP(int x);
void UP(int ins1, int ins2);
bool FP(int ins1, int ins2);

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
	cin >> N >> M;

	// initialization
	for (int i = 0; i < 500001; i++) { parent[i] = i; }

	// processor
	int result = 0, cnt = 1;
	int inp1, inp2;
	bool flag = false;
	for (int i = 0; i < M; i++) {
		cin >> inp1 >> inp2;

		if (flag) { continue; } // found

		if (FP(inp1, inp2)) { // find cycle
			result = cnt; 
			flag = true;
		}
		else { UP(inp1, inp2); } // not find

		cnt++;
	}

	cout << result << "\n";
}

// Get Parent
int GP(int x) {
	if (parent[x] == x) { return x; }
	parent[x] = GP(parent[x]);
	return parent[x];
}

// Union Parent
void UP(int ins1, int ins2) {
	int i1 = GP(ins1);
	int i2 = GP(ins2);

	if (i1 < i2) { parent[i2] = i1; }
	else { parent[i1] = i2; }
}

// Find Parent
bool FP(int ins1, int ins2) {
	int p1 = GP(ins1);
	int p2 = GP(ins2);

	if (p1 == p2) { return true; }
	else { return false; }
}