// Ω∫≈√ (10828) Silver[4]
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
int N;
unordered_map<string, int> um;
stack<int> st;

// Function
void init();
void input();
void solve();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	input();
	solve();

	return 0;
}

// initialization
void init() {
	um["push"] = 1;
	um["pop"] = 2;
	um["size"] = 3;
	um["empty"] = 4;
	um["top"] = 5;
}

// input
void input() {
	cin >> N;
}

// solution
void solve() {
	string inp = "";
	int order = 0;
	int temp = 0;

	for (int i = 0; i < N; i++) {
		cin >> inp;
		order = um[inp];

		switch (order) {
		case 1: // push
			temp = 0;
			cin >> temp;
			st.push(temp);
			break;

		case 2: // pop
			if (st.empty()) { cout << "-1\n"; }
			else {
				temp = st.top();
				st.pop();
				cout << temp << "\n";
			}
			break;

		case 3: // size
			cout << st.size() << "\n";
			break;

		case 4: // empty
			if (st.empty()) { cout << "1\n"; }
			else { cout << "0\n"; }
			break;

		case 5: // top
			if (st.empty()) { cout << "-1\n"; }
			else { cout << st.top() << "\n"; }
			break;

		default: // exception
			cout << "error\n";
			break;
		}

	}

}