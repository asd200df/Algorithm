// LCS (9251) Gold[5]
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
int DP[1005][1005];

// Function
void InSol();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InSol();

	return 0;
}

// input && solution
void InSol() {
	string A, B;
	cin >> A >> B;

	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			char t1 = A[i - 1];
			char t2 = B[j - 1];

			if (t1 == t2) { // 같을 때
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else { // 다를 때 
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
			}
		}
	}

	// int debug = 0;

	cout << DP[A.size()][B.size()] << "\n";
}