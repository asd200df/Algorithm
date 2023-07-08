// °ýÈ£ (9012) Silver[4]
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
int T;
stack<char> st;

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
	cin >> T;
}

// solution
void solve() {
	string inp = "";
	bool flag = true;

	for (int tc = 0; tc < T; tc++) { // test case
		cin >> inp;

		// valid check
		for (int i = 0; i < inp.size(); i++) {
			if (st.empty() && inp[i] == ')') { 
				flag = false;
				break; 
			}

			if (inp[i] == '(') { st.push('('); }
			else {
				if (inp[i] == ')' && st.top() == '(') { st.pop(); }
			}
		}

		// result
		if(flag == false || !st.empty()) { cout << "NO\n"; }
		else { cout << "YES\n"; }

		// initialization
		while (!st.empty()) { st.pop(); }
		flag = true;
	}

}