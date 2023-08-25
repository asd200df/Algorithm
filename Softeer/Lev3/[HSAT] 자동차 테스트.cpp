// 자동차 테스트 [HSAT 7회 정기 코딩 인증평가 기출]
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Global
int N, Q; // N <= 50,000 // Q <= 200,000 // 자동차 연비 <= 1,000,000,000
vector<int> Nvec, Qvec;

// Function
void input();
void solve();
int BS(int tar);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N >> Q;

	int inp;

	for (int i = 0; i < N; i++) {
		cin >> inp;
		Nvec.push_back(inp);
	}

	for (int i = 0; i < Q; i++) {
		cin >> inp;
		Qvec.push_back(inp);
	}

}

// solution
void solve() {

	sort(Nvec.begin(), Nvec.end());

	int mini = Nvec[0];
	int maxi = Nvec[Nvec.size() - 1];

	for (int i = 0; i < Qvec.size(); i++) {
		int target = Qvec[i];

		if (target <= mini || target >= maxi) {
			cout << "0\n";
			continue;
		}

		int idx = BS(target);

		if (idx == -1) { cout << "0\n"; }
		else {
			int front = idx;
			int back = N - (idx + 1);

			cout << front * back << "\n";
		}
	}

}

// binary search
int BS(int tar) {

	int mid;
	int left = 0;
	int right = Nvec.size() - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		int now = Nvec[mid];

		if (now == tar) {
			return mid;
		}
		else if (now < tar) {
			left = mid + 1;
		}
		else { // now > tar
			right = mid - 1;
		}

	}

	return -1;

}