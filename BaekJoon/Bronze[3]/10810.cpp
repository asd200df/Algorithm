// °ø ³Ö±â (10810) Bronze[3]
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
	
	int inp1 = 0;
	int inp2 = 0;
	int inp3 = 0;
	for (int i = 0; i < M; i++) {
		cin >> inp1 >> inp2 >> inp3;

		for(int j = inp1; j <= inp2; j++) { arr[j] = inp3; }
	}

	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	} cout << "\n";
}