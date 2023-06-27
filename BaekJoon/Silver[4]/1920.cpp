// ¼ö Ã£±â (1920) Silver[4]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N, M;
int Nrr[100005], Mrr[100005];

// Function
void input();
void solve();
void BS(int target);

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
	for (int i = 0; i < N; i++) { cin >> Nrr[i]; }
	cin >> M;
	for (int i = 0; i < M; i++) { cin >> Mrr[i]; }
}

// solve
void solve() {

	// sort
	sort(Nrr, Nrr + N);

	// function call
	for (int i = 0; i < M; i++) {
		int target = Mrr[i];
		BS(target);
	}

	/* result print !
	for (int i = 0; i < M; i++) {
		cout << result[Mrr[i]] << "\n";
	}*/
}

// Binary Search
void BS(int target) {
	int start = 0;
	int end = N - 1;
	int mid = (start + end) / 2;
	int flag = 0;

	while (start <= end) {

		if (Nrr[mid] == target) {
			flag = 1;
			break;
		}
		else if (Nrr[mid] < target) {
			start = mid + 1;
		}
		else if (Nrr[mid] > target) {
			end = mid - 1;
		}

		mid = (start + end) / 2;
	}

	if (flag == 1) { cout << "1\n"; }
	else { cout << "0\n"; }
}