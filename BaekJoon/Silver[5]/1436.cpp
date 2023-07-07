// 영화감독 숌 (1436) Silver[5]
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
	int target = 665;
	string temp = "";

	for (int i = 0; i < N; i++) {
		while (true) {
			target++;
			temp = to_string(target);
			if (temp.find("666") != -1) { break; }
		}
	}

	// ※ string.find("target"); >> target을 찾은 맨 앞 인덱스 반환
	// 못 찾으면 429 ... == -1 반환

	cout << target << "\n";
}