// 수학은 비대면강의입니다 (19532) Bronze[2]
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
int a, b, c, d, e, f;

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
	cin >> a >> b >> c >> d >> e >> f;
}

// solution
void solve() {
	int x = 0;
	int y = 0;

	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if (((a*i) + (b*j) == c) && ((d*i) + (e*j) == f)) {
				x = i;
				y = j;
				break;
			}
		}
	}

	cout << x << " " << y << "\n";
}
