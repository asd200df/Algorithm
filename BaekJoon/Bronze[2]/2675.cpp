// 문자열 반복 (2675) Bronze[2]
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
int T;

// Function
void insol();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		insol();
	}

	return 0;
}

// input && solution
void insol() {
	int iter;
	string st, result;

	cin >> iter >> st;

	for (int i = 0; i < st.size(); i++) {
		for (int j = 0; j < iter; j++) {
			result += st[i];
		}
	}

	cout << result << "\n";
}