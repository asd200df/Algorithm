// 단지번호붙이기 (2667) Silver[1]
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
int N; // N <= 26
int map[26][26];
int used[26][26];
int complex_cnt;
int house[676];
int dir[2][4] = { {0, 0, -1, 1}, {1, -1, 0, 0} };
typedef struct {
	int y, x;
}node;
vector<node> vec;

// Function
void input();
void solve();
int FF(node NC);

// Main
int main(int argc, char** argv) {
	FastIO;

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N;
	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			map[i][j] = (temp - '1') + 1;
			if (map[i][j] == 1) { vec.push_back({ i, j }); }
		}
	}
	// int debug = 0;
}

// solution
void solve() {

	int idx = 0;
	for (int i = 0; i < vec.size(); i++) {
		node NeedCheck = vec[i];
		if (used[NeedCheck.y][NeedCheck.x] == 1) { continue; }
		house[idx++] = FF(NeedCheck);
	}
	
	sort(house, house + idx);

	cout << idx << "\n";
	for (int i = 0; i < idx; i++) {
		cout << house[i] << "\n";
	}
}

// Flood Fill
int FF(node NC) {
	int house_cnt = 0;
	queue<node> que;
	que.push({ NC.y, NC.x });

	used[NC.y][NC.x] = 1;
	house_cnt++;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
			if (map[ny][nx] == 0) { continue; }
			if (used[ny][nx] == 1) { continue; }

			if (map[ny][nx] == 1) {
				used[ny][nx] = 1;
				house_cnt++;
				que.push({ ny, nx });
			}
			// int debug = 0;
		}
	}

	return house_cnt;
}