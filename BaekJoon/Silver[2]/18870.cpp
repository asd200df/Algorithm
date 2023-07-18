// 좌표 압축 (18870) Silver[2]
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
typedef struct {
	int value, num;
}node;
vector<node> vec;

// Function
void insol();
bool compare1(node a, node b);
bool compare2(node a, node b);

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N;

	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		vec.push_back({ inp, i });
	}

	// First sort
	sort(vec.begin(), vec.end(), compare1);

	// 압축
	int  inc = -1;
	int prefix = -21e8;
	for (int i = 0; i < N; i++) {

		if (i != 0) {
			if (vec[i].value == prefix) {
				vec[i] = { inc, vec[i].num };
				continue;
			}
		}

		prefix = vec[i].value;
		vec[i] = { ++inc, vec[i].num }; 
	}

	// Second sort
	sort(vec.begin(), vec.end(), compare2);

	// Print result
	for (int i = 0; i < N; i++) { cout << vec[i].value << " "; }
	cout << "\n";
}

bool compare1(node a, node b) {
	if (a.value < b.value) { return true; }
	else { return false; }
}

bool compare2(node a, node b) {
	if (a.num < b.num) { return true; }
	else { return false; }
}