// Ω∫≈√ 2 (28278) Silver[4]
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
int N;

// Function
void insol();

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
	cin >> N;

	stack<int> st;
	int order;
	for (int i = 0; i < N; i++) {
		cin >> order;

		switch (order) {
		case 1:
			int n;
			cin >> n;
			st.push(n);
			break;
		case 2:
			if (st.empty()) { cout << "-1\n"; }
			else {
				cout << st.top() << "\n";
				st.pop();
			}
			break;
		case 3:
			cout << st.size() << "\n";
			break;
		case 4:
			cout << st.empty() << "\n";
			break;
		case 5:
			if (st.empty()) { cout << "-1\n"; }
			else { cout << st.top() << "\n"; }
			break;
		default:
			cout << "error\n";
			break;
		}
	}

}