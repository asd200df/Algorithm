// 좌표 정렬하기 (11650) Silver[5]
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
	int x, y;
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
	cin >> N;

	int ix, iy;
	for (int i = 0; i < N; i++) {
		cin >> ix >> iy;
		vec.push_back({ ix, iy });
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << vec[i].x << " " << vec[i].y << "\n";
	}
}

// sort compare
bool compare(node a, node b) {
	if (a.x < b.x) { return true; }
	else if (a.x == b.x) { return a.y < b.y; }
	else { return false; }
}