// µ¿Àü 0 (11047) Silver[4]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

#define fastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int N, K;
int coin[11];

// Function
void insol();

// Main
int main(int argc, char** argv) {
	fastIO;

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N >> K;

	int cnt = 0;

	for (int i = 0; i < N; i++) { cin >> coin[i]; }
	sort(coin, coin + N, greater<int>());

	int idx = 0;
	int target = K;
	while (target >= 0) {
		int now = coin[idx];

		if (target == now) {
			cnt++;
			break;
		}
		else if (target >= now) {
			target -= now;
			cnt++;
		}
		else { idx++; } // target < now

	}

	cout << cnt << "\n";
}