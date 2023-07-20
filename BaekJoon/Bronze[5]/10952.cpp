// A+B - 5 (10952) Bronze[5]
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
	
	int A = 0;
	int B = 0;
	while (true) {
		cin >> A >> B;

		if (A == 0 && B == 0) { break; }
		
		cout << A + B << "\n";
	}

}