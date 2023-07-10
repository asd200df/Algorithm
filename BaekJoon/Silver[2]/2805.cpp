// 나무 자르기 (2805) Silver[2]
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
int N;	// 1,000,000
long M;	// 2,000,000,000
long max_tree;
long tree[1000001];

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

// input(
void input() {
	max_tree = -21e8;

	cin >> N >> M;
	for (int i = 0; i < N; i++) { 
		cin >> tree[i]; 
		max_tree = max(max_tree, tree[i]);
	}
}

// solve
void solve() {
	long long maxi = -21e8;

	// sort(tree, tree + N);

	long L = 0;
	long R = max_tree;
	long long mid;
	long long sum;
	while (L <= R) {
		sum = 0;
		mid = (L + R) / 2;

		for (int i = 0; i < N; i++) {
			if (tree[i] >= mid) { sum += tree[i] - mid; }
		}

		if (sum == M) {
			maxi = mid;
			break;
		}
		else if (sum > M) {
			maxi = max(maxi, mid);
			L = ++mid;
		}
		else { // sum < M
			R = --mid;
		}

	}

	if (maxi == -21e8) { cout << "0\n"; }
	else { cout << maxi << "\n"; }
}