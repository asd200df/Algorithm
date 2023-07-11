// 주사위 세개 (2480) Bronze[4]
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
int dice1, dice2, dice3;

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
	cin >> dice1 >> dice2 >> dice3;

	int maxi = dice1;
	maxi = max(maxi, dice2);
	maxi = max(maxi, dice3);
	int result = 0;

	// 1. 같은 3개 >> 10,000원+(같은 눈)×1,000원 
	// 2. 모두 다른 눈 >> (그 중 가장 큰 눈)×100원
	// 3. 같은 2개 >> 1, 000원 + (같은 눈)×100원

	if(dice1 == dice2 && dice2 == dice3) { result = 10000 + (dice1 * 1000); }
	else if (dice1 != dice2 && dice2 != dice3 && dice1 != dice3) {
		result = maxi * 100; 
	}
	else {
		int temp = 0;
		if (dice1 == dice2) { temp = dice1; }
		else if (dice2 == dice3) { temp = dice2; }
		else { temp = dice3; }
		result = 1000 + (temp * 100);
	}

	cout << result << "\n";
}
