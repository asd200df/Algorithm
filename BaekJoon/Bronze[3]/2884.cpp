// 알람 시계 (2884) Bronze[3]
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
int H, M;

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

// input & solution
void insol() {
	cin >> H >> M;

	M -= 45;

	if (M < 0) {
		M += 60;
		
		H -= 1;
	
		if (H < 0) {
			H += 24;
		}
	}

	cout << H << " " << M << "\n";
}
