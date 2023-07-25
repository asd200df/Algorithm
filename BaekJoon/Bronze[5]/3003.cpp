// Å·, Äý, ·è, ºñ¼ó, ³ªÀÌÆ®, Æù (3003) Bronze[5]
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int set[6] = { 1, 1, 2, 2, 2, 8 };

// Function
void insol();

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input && solution
void insol() {

	int inp;
	for (int i = 0; i < 6; i++) {
		cin >> inp;

		if (set[i] == inp) { cout << "0 "; }
		else { cout << set[i] - inp << " "; }
	} cout << "\n";

}