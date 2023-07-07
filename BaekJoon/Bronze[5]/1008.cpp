// A/B (1008) Bronze[5]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stdio.h>

using namespace std;

// Global
double A, B;

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
	cin >> A >> B;
}

// solution
void solve() {
	printf("%.13lf", A / B);
	printf("\n");
}