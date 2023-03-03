// 8단 변속기 
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
int arr[9];

// Function
void input();
string solve();

// MAIN
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	string result = solve();

	cout << result << "\n";

	return 0;
}

// input
void input() {
	for (int i = 0; i < 8; i++) { cin >> arr[i]; }
}

// solution
string solve() {
	string ret = "mixed";
	int valid = 0;
	int asc = 0, des = 0;

	// count
	for (int i = 1; i < 8; i++) {
		if (arr[i - 1] == (arr[i] - 1)) asc++;
		else if ((arr[i - 1] - 1) == arr[i]) des++;
	}

	// check
	if (asc == 7) ret = "ascending";
	else if (des == 7) ret = "descending";

	return ret; // temp
}