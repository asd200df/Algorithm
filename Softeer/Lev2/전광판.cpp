// [21년 재직자 대회 예선] 전광판
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

// Global
int num1, num2;
int n1[5], n2[5];
int allzero[7] = { 0, 0, 0, 0, 0, 0, 0 };	// all zero set
int segment[10][7] = {
	//	{0, 1, 2, 3, 4, 5, 6}	// 7segment num
		{1, 1, 1, 1, 1, 1, 0},	// 0 (6)
		{0, 1, 1, 0, 0, 0, 0},	// 1 (2)
		{1, 1, 0, 1, 1, 0, 1},	// 2 (5)
		{1, 1, 1, 1, 0, 0, 1},	// 3 (5)
		{0, 1, 1, 0, 0, 1, 1},	// 4 (4)	
		{1, 0, 1, 1, 0, 1, 1},	// 5 (5)
		{1, 0, 1, 1, 1, 1, 1},	// 6 (6)
		{1, 1, 1, 0, 0, 1, 0},	// 7 (4)
		{1, 1, 1, 1, 1, 1, 1},	// 8 (7)
		{1, 1, 1, 1, 0, 1, 1}	// 9 (6)
};

// Function
void init();
void input();
int solve();
int isValid(int i);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		input();
		int result = solve();

		cout << result << "\n";
	}

	return 0;
}

// initialization
void init() {
	num1 = 0;
	num2 = 0;
	memset(n1, 0, sizeof(n1));
	memset(n2, 0, sizeof(n2));
}

// input
void input() {
	cin >> num1 >> num2;
	int tn1 = num1;
	int tn2 = num2;
	int chk1 = 1;
	int chk2 = 1;
	memset(n1, -1, sizeof(n1));
	memset(n2, -1, sizeof(n2));

	for (int i = 4; i >= 0; i--) {
		if (chk1 == 1) {
			n1[i] = tn1 % 10;
			tn1 = tn1 / 10;
			if (tn1 == 0) chk1 = -1;
		}
		if (chk2 == 1) {
			n2[i] = tn2 % 10;
			tn2 = tn2 / 10;
			if (tn2 == 0) chk2 = -1;
		}
	}

	/* debug
	for(int i = 0 ; i < 5; i++){
		cout << n1[i] << endl;
	} cout << " ---------- " << endl;
		for(int i = 0 ; i < 5; i++){
		cout << n2[i] << endl;
	}cout << " ---------- " << endl;
	*/
}

// solution
int solve() {
	int tmp = 0;

	for (int i = 0; i < 5; i++) {
		tmp += isValid(i);
	}

	return tmp;
}

// valid check
int isValid(int i) {
	int idx1 = n1[i];
	int idx2 = n2[i];
	int diff = 0;

	if (idx1 == idx2) {
		// cout << "debug diff 1 : " << diff << "\n";
		return diff;	// 차이가 없는 경우 
	}

	else if (idx1 == -1 || idx2 == -1) {	// 둘 중 하나만 다 꺼져있는 경우
		if (idx1 == -1) {
			for (int k = 0; k < 7; k++) {
				if (segment[idx2][k] != allzero[k]) diff++;
			}
		}
		else {
			for (int k = 0; k < 7; k++) {
				if (segment[idx1][k] != allzero[k]) diff++;
			}
		}
		// cout << "debug diff 2 : " << diff << "\n";
		return diff;
	}

	else {	// 차이가 있는 경우 (꺼진 숫자 없이)
		for (int k = 0; k < 7; k++) {
			if (segment[idx1][k] != segment[idx2][k]) diff++;
		}
		// cout << "debug diff 3 : " << diff << "\n";
		return diff;
	}
}