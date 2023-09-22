// 여행 가자 (1976) Gold[4]
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
int N; // <= 200
int M; // <= 1,000
int parent[202];

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

	// init
	for (int i = 1; i < 202; i++) { parent[i] = i; }

	// update
	int inp = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> inp;
			if (inp == 0) { continue; }
			else { UP(i, j); }
		}
	}

	// last input;
	int arr[1002];
	for (int i = 0; i < M; i++) { cin >> arr[i]; }

	// valid check
	bool flag = true;
	for (int i = 1; i < M; i++) {
		if (FP(arr[i - 1], arr[i])) { continue; }
		else { flag = false; }
	}

	// print
	if (flag) { cout << "YES\n"; }
	else { cout << "NO\n"; }
}

// Get Parent
int GP(int x) {
	if (parent[x] == x) { return x; }
	parent[x] = GP(parent[x]);
	return parent[x];
}

// union Parent
void UP(int ins1, int ins2) {
	int P1 = GP(ins1);
	int P2 = GP(ins2);

	if (P1 < P2) { parent[P2] = P1; }
	else { parent[P1] = P2; }
}

// Find Parent 
bool FP(int ins1, int ins2) {
	int P1 = GP(ins1);
	int P2 = GP(ins2);

	if (P1 == P2) { return true; }
	else { return false; }
}