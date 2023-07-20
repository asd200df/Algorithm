// 바구니 뒤집기 (10811) Bronze[2]
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
	stack<int> st;
	for (int i = 0; i < M; i++) {
		cin >> inp1 >> inp2;

		for (int k = inp1; k <= inp2; k++) { st.push(arr[k]); }

		int idx = inp1;
		while (!st.empty()) {
			temp = st.top();
			st.pop();
			arr[idx++] = temp;
		}

	}

	for (int i = 1; i <= N; i++) { cout << arr[i] << " "; }
	cout << "\n";
}