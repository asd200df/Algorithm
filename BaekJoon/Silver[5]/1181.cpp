// 단어 정렬 (1181) Silver[5]
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
int N;
vector<string> vec;

// Function
void insol();
bool compare(string a, string b);

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N;

	string inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		vec.push_back(inp);
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++) { 
		if (i != 0) {
			if (vec[i] == vec[i - 1]) { continue; }
		}

		cout << vec[i] << "\n"; 
	}
}

// sort compare
bool compare(string a, string b) {
	if (a.size() < b.size()) { return true; }
	else if (a.size() == b.size()) { return a < b; }
	else { return false; }
}