// 수 정렬하기 2 (2751) Silver[5]
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
int N;
int arr[1000001];

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
	cin >> N;

	for (int i = 0; i < N; i++) { cin >> arr[i]; }

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) { cout << arr[i] << "\n"; }
}
