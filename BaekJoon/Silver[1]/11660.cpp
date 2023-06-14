// 구간 합 구하기 5 (11660) Silver[1]
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Global
int N, M;
int map[1030][1030];
int cs[1030][1030];
typedef struct {
	int y, x;
}node;
vector<node> vec1, vec2;

// Function
void input();
void solve();
void cumsum();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int ay = 0, ax = 0, by = 0, bx = 0;
	for (int i = 0; i < M; i++) {
		cin >> ay >> ax >> by >> bx;
		vec1.push_back({ ay, ax });
		vec2.push_back({ by, bx });
	}
}

// solution
void solve() {

	cumsum();

	int up = 0;
	int left = 0;
	int dupli = 0;
	int ego = 0;
	int result = 0;
	for (int i = 0; i < vec1.size(); i++) {
		up = cs[vec1[i].y - 1][vec2[i].x];
		left = cs[vec2[i].y][vec1[i].x - 1];
		dupli = cs[vec1[i].y - 1][vec1[i].x - 1];
		ego = cs[vec2[i].y][vec2[i].x];

		result = ((ego - up) - left) + dupli;

		cout << result << "\n";
	}

}

// cumulative sum
void cumsum() {
	int up = 0;
	int left = 0;
	int dupli = 0;
	int ego = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			up = cs[i - 1][j];
			left = cs[i][j - 1];
			dupli = cs[i - 1][j - 1];
			ego = map[i][j];

			cs[i][j] = ((up + left) - dupli) + ego;
		}
	}
}