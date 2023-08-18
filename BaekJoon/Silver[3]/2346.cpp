// «≥º± ≈Õ∂ﬂ∏Æ±‚ (2346) Silver[3]
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
typedef struct {
	int num, seq;
}node;
deque<node> dq;
vector<int>vec;

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

	// input
	int inp;
	for(int i = 1; i <= N; i++) {
		cin >> inp;
		dq.push_back({ i, inp });
	}

	// calculator
	while (!dq.empty()) {
		int nn = dq.front().num;
		int ns = dq.front().seq;

		vec.push_back(nn);

		for (int i = 0; i < abs(ns); i++) {
			if (dq.empty()) { break; }

			if (ns > 0) {
				if (i != 0) { dq.push_back({ dq.front() }); }
				dq.pop_front();
			}
			else { // ns <= 0
				if (i == 0) { dq.pop_front(); }
				dq.push_front({ dq.back() });
				dq.pop_back();
			}
		}

	}

	// print result !
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	} cout << "\n";
}