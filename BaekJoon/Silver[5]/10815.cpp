// 숫자 카드 (10815) Silver[5]
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
int N, M; // N, M <= 500,000
vector<int> vec;

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
	int inp, idx;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		vec.push_back(inp);
	}

	sort(vec.begin(), vec.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> inp;

		// int debug = 0;

		idx = lower_bound(vec.begin(), vec.end(), inp) - vec.begin();

		if (idx == N || idx < 0) {
			cout << "0 ";
			continue;
		}

		if (inp == vec[idx]) { cout << "1 "; }
		else { cout << "0 "; }
	}

	cout << "\n";

}