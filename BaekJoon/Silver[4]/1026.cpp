// º¸¹° (1026) Silver[4]
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

using namespace std;

// global
int N; // <= 50
int Arr[55], Brr[55];

// function
void insol();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insol();

	return 0;
}

// input && solve
void insol() {
	cin >> N;

	for (int i = 0; i < N; i++) { cin >> Arr[i]; }
	for (int i = 0; i < N; i++) { cin >> Brr[i]; }

	sort(Arr, Arr + N);
	sort(Brr, Brr + N, greater<int>());

	int result = 0;
	for (int i = 0; i < N; i++) {
		int A = Arr[i];
		int B = Brr[i];

		result += (A * B);
	}

	cout << result << "\n";
}