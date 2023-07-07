// ºÐÇØÇÕ (2231) Bronze[2]
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
int N;

// Function
void input();
void solve();

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
}

// solution
void solve() {
	int result = 0;
	int roof;
	int temp = 0;

	for (int i = 0; i <= N; i++) {
		temp = roof = i;

		while (roof) {
			temp += roof % 10;
			roof = roof / 10;
		}

		if (temp == N) { 
			result = i;
			break;
		}
	}

	if (temp == N) { cout << result << "\n"; }
	else { cout << "0\n"; }
}