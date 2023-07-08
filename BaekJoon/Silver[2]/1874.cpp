// 스택 수열 (1874) Silver[2]
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
int N; // <= 100000
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
	cin >> N;
}

// solution
void solve() {
	vector<char> result;
	int inp = 0;
	int cnt = 1;

	for (int i = 0; i < N; i++) {
		cin >> inp;

		while (cnt <= inp) {
			st.push(cnt);
			result.push_back('+');
			cnt++;
		}

		if (st.top() == inp) {
			st.pop();
			result.push_back('-');
		}

	}

	if (st.empty() == false) { cout << "NO\n"; }
	else { 
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n"; 
		} 
	}
}