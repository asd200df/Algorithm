// ÃÖ¼Ú°ª Ã£±â (11003) Platinum[5]
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
int N, L; // N <= 1,000,000,000 // L <= 5,000,000
// typedef struct { int num, idx; }node;

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
	cin >> N >> L;

	typedef pair<int, int> p;

	priority_queue<p, vector<p>, greater<p>> pq;

	int inp, lim;
	for (int i = 0; i < N; i++) {
		cin >> inp;

		lim = i - L + 1;

		pq.push({ inp, i });
		
		if (!pq.empty()) {
			while (pq.top().second < lim) { pq.pop(); }
		}
		
		cout << pq.top().first << " ";
	}
	
	cout << "\n";
}