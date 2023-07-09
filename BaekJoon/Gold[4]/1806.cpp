// ºÎºÐÇÕ (1806) Gold[4]
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
int N; // <= 100,000
long long S; // <= 100,000,000
long long arr[100001];
bool flag = false;

// Function
void input();
void solve();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	if (flag == false) { solve(); }
	else { cout << "1\n"; }

	return 0;
}

// input
void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) { 
		cin >> arr[i]; 
		if (arr[i] == S) { flag = true; }
	}
}

// solution
void solve() {
	int mini = 21e8;
	int target = S;

	int L = 0;
	int R = 0;
	int now = arr[0];
	while (L <= R && R < N) {

		if (now >= target) {
			mini = min(abs(R - L) + 1, mini);
			now -= arr[L++];
			if (L > R) {
				R = L;
				now = arr[L];
			}
		}
		else if (now < target) {
			now += arr[++R];
		}

	}

	if (mini == 21e8) { mini = 0; }
	cout << mini << "\n";
}