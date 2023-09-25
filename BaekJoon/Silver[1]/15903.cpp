// 카드 합체 놀이 (15903) Silver[1]
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

// Global
int N; // <= 2 ~ 1,000
int M; // <= 0 ~ n * 15

// Function
void insolve();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insolve();

	return 0;
}

// input && solution
void insolve() {
	cin >> N >> M;

	priority_queue<long long, vector<long long>, greater<long long>> pq;

	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		pq.push(inp);
	}

	long long num1, num2;
	for (int i = 0; i < M; i++) {
		num1 = pq.top();
		pq.pop();
		num2 = pq.top();
		pq.pop();
		pq.push(num1 + num2);
		pq.push(num1 + num2);
	}

	long long sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum << "\n";
}