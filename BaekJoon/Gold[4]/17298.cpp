// ¿ÀÅ«¼ö (17298) Gold[4]
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
int N;

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

	cin >> N; // <= 1,000,000

	vector<int> vec(N);
	stack<int> value, index;

	int inp, target;

	cin >> inp;
	value.push(inp);
	index.push(0);

	int vtmp = 0;
	int itmp = 0;
	for (int idx = 1; idx < N; idx++) {
		target = value.top();
		cin >> inp;

		if (target < inp) {	

			while (!value.empty()) {
				vtmp = value.top();
				itmp = index.top();

				if (vtmp < inp) {
					vec[itmp] = inp;

					value.pop();
					index.pop();
				}
				else { break; }
			}

		}

		value.push(inp);
		index.push(idx);
	}

	while (!value.empty()) {
		vec[index.top()] = -1;

		value.pop();
		index.pop();
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	} cout << "\n";
}