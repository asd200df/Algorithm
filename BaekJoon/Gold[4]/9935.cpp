// 문자열 폭발 (9935) Gold[4]
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
string target;
string boom;

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
	cin >> target >> boom;

	/* 비교를 쉽게 하기 위해 폭탄 뒤집기
	string boom;
	for (int i = temp_boom.size() - 1; i >= 0; i--) {
		boom += temp_boom[i];
	}*/

	// compare && update
	stack<char> st;
	bool flag = true;
	string now = target;
	int before = 0;
	while (flag) {
		before = now.size();

		for (int i = now.size() - 1; i >= 0; i--) {
			string temp;
			st.push(now[i]); // 하나씩 꺼내서 넣음

			if (st.size() >= boom.size()) {
				for (int j = boom.size() - 1; j >= 0; j--) {
					temp += st.top();
					st.pop();
				}

				if (temp != boom) {
					for (int k = temp.size() - 1; k >= 0; k--) {
						st.push(temp[k]);
					}
				}
			}
		}

		int debug = 0;
		if (before != now.size()){
			while (!st.empty()) {
				now = st.top();
				st.pop();
			}
			debug = 1;
		}

		else { flag = false; }
	}

	// print result !
	if (st.empty()) { cout << "FRULA\n"; }
	else {
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
		cout << "\n";
	}

}