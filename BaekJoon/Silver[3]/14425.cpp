// 문자열 집합 (14425) Silver[3]
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
int N, M;

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

// input && solution
void insol() {
	unordered_map<string, int> um;
	vector<string> vec;
	int cnt = 0;

	cin >> N >> M;

	string inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		vec.push_back(inp);
	}

	for (int i = 0; i < M; i++) {
		cin >> inp;
		um[inp]++;
	}

	for (auto iter : vec) {
		cnt += um[iter];
	}

	cout << cnt << "\n";
}