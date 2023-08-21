// 맥주 마시면서 걸어가기 (9205) Gold[5]
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
int T, csn;
int used[105]; 
typedef struct { int y, x; }node;
vector<node> cs; // convenience store
node home, festival;

// Function
void init();
void input();
void solve();
bool BFS();
bool dis(int ny, int nx, int gy, int gx);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		input();
		solve();
	}

	return 0;
}

// initialization
void init() {
	memset(used, 0, sizeof(used));
	cs.clear();
}

// input
void input() {
	cin >> csn;

	cin >> home.y >> home.x;

	int iy, ix;
	for (int i = 0; i < csn; i++) { 
		cin >> iy >> ix;
		cs.push_back({iy, ix});
	}

	cin >> festival.y >> festival.x;
}

// solution
void solve() {
	string result;

	if (BFS()) { result = "happy"; }
	else { result = "sad"; }

	cout << result << "\n";
}

// Breadth-First Search
bool BFS() {
	queue<node> que;
	que.push({ home.y, home.x });

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		// 목적지 도착 가능
		if (dis(now.y, now.x, festival.y, festival.x)) { return true; }

		// convenience store searching ...
		for (int i = 0; i < cs.size(); i++) {
			int next_y = cs[i].y;
			int next_x = cs[i].x;

			// distance check
			if (!dis(now.y, now.x, next_y, next_x)) { continue; }
			int debug2 = 0;

			// used check
			if (used[i] == 1) { continue; }

			// used update
			used[i] = 1;

			// que push
			que.push({ next_y, next_x });
		}
	}

	return false;
}

// distance
bool dis(int ny, int nx, int gy, int gx) {
	int dif_y = abs(ny - gy);
	int dif_x = abs(nx - gx);

	if ((dif_y + dif_x) <= 1000) { return true; }
	else { return false; }
}