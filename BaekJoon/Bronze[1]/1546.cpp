// ЦђБе (1546) Bronze[1]
#include<iostream>
#include<stdio.h>
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
int N;
int score[1001];

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
	cin >> N;

	int sum = 0;
	int maxi = -21e8;
	for (int i = 0; i < N; i++) { 
		cin >> score[i]; 
		sum += score[i];
		maxi = max(maxi, score[i]);
	}

	printf("%f\n", (((sum * 100.0) / maxi) / N));
}