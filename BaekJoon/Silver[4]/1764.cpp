// µË∫∏¿‚ (1764) Silver[4]
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

	cin >> N >> M;

	string inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		um[inp]++;
	}

	for (int i = 0; i < M; i++) {
		cin >> inp;
		um[inp]++;

		if (um[inp] > 1) { vec.push_back(inp); }
	}

	sort(vec.begin(), vec.end());

	cout << vec.size() << "\n";
	for (auto iter : vec) {
		cout << iter << "\n";
	}
}