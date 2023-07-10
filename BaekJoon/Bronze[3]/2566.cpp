// ÃÖ´ñ°ª (2566) Bronze[3]
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
int arr[10][10];

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

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> arr[i][j];
			if (maxi < arr[i][j]) {
				maxi = arr[i][j];
				y = i;
				x = j;
			}
		}
	}

	cout << maxi << "\n" << y << " " << x << "\n";
}