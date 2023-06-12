// 숫자 카드 2 (10816) Silver[4]
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// [Global]
int N, M;
int Nrr[500001];
int Mrr[500001];
unordered_map<int, int> um;

// [Function]
// input
void input() { 
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> Nrr[i]; }
	cin >> M;
	for (int i = 0; i < M; i++) { cin >> Mrr[i]; }
}

// Binary Search
bool BS(int target) { 
	int start = 0;
	int end = N - 1;
	int mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		if (Nrr[mid] == target) { // Find !!
			return true;
		}
		else if (Nrr[mid] > target) { // target < mid
			end = mid - 1;
		}
		else { // target > mid
			start = mid + 1;
		}
	}

	return false;
}

// Solution
void solve() { 

	sort(Nrr, Nrr + N);

	for (int i = 0; i < M; i++) {
		int target = Mrr[i];

		if (BS(target)) {
			int up = upper_bound(Nrr, Nrr + N, target) - Nrr;
			int low = lower_bound(Nrr, Nrr + N, target) - Nrr;
			int total = up - low;

			um[target] = total;
		}
		
	}

	// print
	for (int i = 0; i < M; i++) {
		cout << um[Mrr[i]] << " ";
	} cout << "\n";
}

// [Main]
int main(int argc, char** argv){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}