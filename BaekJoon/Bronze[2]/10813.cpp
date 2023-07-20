// 공 바꾸기 (10813) Bronze[2]
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
int N, M;
int arr[101];

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
	cin >> N >> M;

	for (int i = 1; i <= N; i++) { arr[i] = i; }
	
	int inp1 = 0;
	int inp2 = 0;
	int temp = 0;
	for (int i = 0; i < M; i++) {
		cin >> inp1 >> inp2;

		// swap
		temp = arr[inp1];
		arr[inp1] = arr[inp2];
		arr[inp2] = temp;
	}

	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	} cout << "\n";
}