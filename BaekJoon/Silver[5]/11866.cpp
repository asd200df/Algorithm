// 요세푸스 문제 0 (11866) Silver[5]
#include<iostream>
#include<string>
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
int N, K; // <= 1000

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
	cin >> N >> K;

	int result[1001];
	queue<int> que;
	
	for (int i = 1; i <= N; i++) { que.push(i); }

	int cnt = 1;
	int idx = 0;
	int now = 0;
	while (!que.empty()) {
		now = que.front();
		que.pop();

		if (cnt == K) {
			result[idx++] = now;
			cnt = 1;
			continue;
		}

		que.push(now);

		cnt++;
	}

	cout << "<";
	for (int i = 0; i < N; i++) { 
		cout << result[i];
		if (i != N - 1) { cout << ", "; }
	} cout << ">\n";
}