// 회사에 있는 사람 (7785) Silver[5]
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
int N; // <= 10^6 == 1,000,000

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
	
	unordered_map<string, bool> um;
	vector<string> vec;

	cin >> N;

	string inp, ord;
	for (int i = 0; i < N; i++) {
		cin >> inp >> ord;

		if (ord == "enter") { um[inp] = true; }
		else { um[inp] = false; }
	}

	for (auto ite : um) {
		if (ite.second) {
			vec.push_back(ite.first);
		}
	}

	sort(vec.begin(), vec.end(), greater<string>());

	for (auto ite : vec) {
		cout << ite << "\n";
	}
}