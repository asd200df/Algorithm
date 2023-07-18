// ¾à¼ö (1037) Bronze[1]
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
int num;

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
	cin >> num;

	vector<int> vec;

	int inp;
	for (int i = 0; i < num; i++) {
		cin >> inp;
		vec.push_back(inp);
	}

	sort(vec.begin(), vec.end());

	int result = 0;
	result = vec[0] * vec[num - 1];
	cout << result << "\n";
}