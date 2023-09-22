// 집합의 표현 (1717) Gold[5]
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
int N; // <= 1,000,000
int M; // <= 100,000
int parent[1000001];

// Function
void insol();
int GP(int x);
void UP(int a, int b);
bool FP(int a, int b);

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
	for (int i = 0; i < 1000001; i++) { parent[i] = i; }

	// processor
	int order, inp1, inp2;
	for (int i = 0; i < M; i++) {
		bool ret = false;

		cin >> order >> inp1 >> inp2;

		if (order == 0) { UP(inp1, inp2); }
		else { 
			if (FP(inp1, inp2)) { ret = true; }
			if (ret) { cout << "YES\n"; }
			else { cout << "NO\n"; }
		}
	}
}

// get Parent
int GP(int x) {
	if (parent[x] == x) { return x; }
	parent[x] = GP(parent[x]);
	return parent[x];
}

// union Parent 
void UP(int a, int b) {
	int A = GP(a);
	int B = GP(b);

	if (A < B) { parent[B] = A; }
	else { parent[A] = B; }
}

// find Parent 
bool FP(int a, int b) {
	int A = GP(a);
	int B = GP(b);

	if (A == B) { return true; }
	else { return false; }
}