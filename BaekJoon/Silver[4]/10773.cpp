// Á¦·Î (10773) Silver[4]
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
int K; // <= 100000
stack<int> st;

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
	cin >> K;
	
	int order = 0;
	for(int i = 0; i < K; i++) { 
		cin >> order;
		if (order != 0) { st.push(order); }
		else { st.pop(); }
	}
}

// solution
void solve() {
	int sum = 0;

	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	cout << sum << "\n";
}