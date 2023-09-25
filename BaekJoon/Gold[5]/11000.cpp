// 강의실 배정 (11000) Gold[5]
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
int N; // <= 200,000
// (0 ≤ Si < Ti ≤ 109)
typedef struct { int s, e; }node;
vector<node> vec;

// Function
void input();
void solve();
bool compare(node a, node b) {
	if (a.s < b.s) { return true; }
	else { return false; }
}

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
	cin >> N;
	
	int inp_s, inp_t;
	for (int i = 0; i < N; i++) {
		cin >> inp_s >> inp_t;
		vec.push_back({ inp_s, inp_t });
	}
}

// solution
void solve() {

	sort(vec.begin(), vec.end(), compare);

	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(vec[0].e);
	for (int i = 1; i < vec.size(); i++) {
		int pt = pq.top();
		int target = vec[i].s;

		if (pt <= target) {
			pq.pop();
			pq.push(vec[i].e);
		}
		else {
			pq.push(vec[i].e);
		}

	}

	cout << pq.size() << "\n";

}