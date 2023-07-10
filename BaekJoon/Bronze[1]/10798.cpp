// 세로읽기 (10798) Bronze[1]
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
char arr[5][16];

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

// input && solution
void insol() {
	int maxi = -21e8;
	int y = 0;
	int x = 0;

	for (int i = 0; i < 5; i++) { cin >> arr[i]; }

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != NULL) { cout << arr[j][i]; }
		}
	} 

	cout << "\n";
}