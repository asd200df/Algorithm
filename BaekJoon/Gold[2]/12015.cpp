// 가장 긴 증가하는 부분 수열 2 (12015) Gold[2]
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

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int N;
vector<int> vec;

// Function
void insol();

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N;

	vec.push_back(0);
	int inp, idx;
	for (int i = 0; i < N; i++) {
		cin >> inp;

		if (vec.back() == inp) { continue; }

		if (vec.back() > inp) {
			idx = lower_bound(vec.begin(), vec.end(), inp) - vec.begin();
			vec[idx] = inp;
		}
		else { // vec.back() < inp
			vec.push_back(inp);
		}
	}

	cout << vec.size() - 1 << "\n";
}