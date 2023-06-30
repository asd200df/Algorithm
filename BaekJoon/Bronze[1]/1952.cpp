// ¥ﬁ∆ÿ¿Ã (1952) Bronze[1]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N, M, total;
int dir[2][4] = { { 0, 1, 0, -1 }, { 1, 0, -1, 0 } }; // øÏ «œ ¡¬ ªÛ
int used[101][101];
typedef struct {
	int y, x;
}node;

// Function
void input();
void solve();
void cal();

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
}

// solution
void solve() {

	cal();

	cout << total << "\n";
}

// Calculator
void cal() {
	int idx = 0; // 0øÏ, 1«œ, 2¡¬, 3ªÛ
	int ny = 0;
	int nx = 0;
	int cnt = 1;
	node now = { 0, 0 };

	used[0][0] = 1;

	while (cnt != (N * M)) {

		if (idx == 4) { idx = 0; }
		ny = now.y + dir[0][idx];
		nx = now.x + dir[1][idx];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
			idx++;
			total++;
			continue;
		}
		if (used[ny][nx] == 1) {
			idx++;
			total++;
			continue;
		} 

		used[ny][nx] = 1;
		cnt++;
		now.y = ny;
		now.x = nx;
	}

}