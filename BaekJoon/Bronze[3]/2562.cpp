// ÃÖ´ñ°ª (2562) Bronze[3]
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
int N; // 1,000,000
typedef struct {
	int idx, num;
}node;
vector<node> vec;

// Function
void insol();
bool compare(node a, node b);

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input && solution
void insol() {

	int inp;
	for (int i = 0; i < 9; i++) { 
		cin >> inp;
		vec.push_back({ i+1, inp });
	}

	sort(vec.begin(), vec.end(), compare);

	cout << vec[0].num << "\n" << vec[0].idx << "\n";
}

// sort compare
bool compare(node a, node b) {
	if (a.num > b.num) { return true; }
	else { return false; }
}