// 균형잡힌 세상 (4949) Silver[4]
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
// -

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

// input & solution
void insol() {
	stack<char> st;
	string inp;
	bool flag = true;

	// 공백 있이 입력 받고 싶을 때 1
	cin.ignore();

	while (true) {
		getline(cin, inp); // 2

		// end condition
		if (inp == ".") { break; }

		// valid check
		for (int i = 0; i < inp.size(); i++) {
			if(inp[i] != '(' && inp[i] != ')' && 
				inp[i] != '[' && inp[i] != ']') { continue; }

			if (st.empty() && inp[i] == ')' ||
				st.empty() && inp[i] == ']') {
				flag = false;
				break;
			}

			if(inp[i] == '(' || inp[i] == '[') { st.push(inp[i]); }
			else {
				if (st.top() == '(') {
					if (inp[i] == ')') { st.pop(); }
					else {
						flag = false;
						break;
					}
				}
				else if (st.top() == '[') {
					if (inp[i] == ']') { st.pop(); }
					else {
						flag = false;
						break;
					}
				}
			}

		}

		// result
		if (flag == false || !st.empty()) { cout << "no\n"; }
		else { cout << "yes\n"; }

		// initialization
		while (!st.empty()) { st.pop(); }
		flag = true;
	}

}