// 가장 긴 증가하는 부분 수열 3 (12738) Gold[2]
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
vector<long long> vec;

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

	// vector minimum initialization
	vec.push_back(-21e8);

	// input & update
	long long inp = 0;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		cin >> inp;

		if (vec.back() == inp) { continue; }

		if (vec.back() < inp) { vec.push_back(inp); }
		else { // vec.back() > inp
			idx = lower_bound(vec.begin(), vec.end(), inp) - vec.begin();
			vec[idx] = inp;
		}
	}

	// print result
	cout << vec.size() - 1 << "\n";
}