// 동계 테스트 시점 예측
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
int N, M;
int map[101][101];
int used[101][101];
int dirX[] = { 0, 0, -1, 1 };
int dirY[] = { -1, 1, 0, 0 };
typedef struct {
	int y, x;
}str;
queue<str> ice_que;
queue<str> air_que;
// queue<str> chg_que;

// Function
void input();
int solve();
void Floodfill();
void BFS();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	int debug = 0;
	int result = solve();

	cout << result << "\n";

	return 0;
}

// input
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) { ice_que.push({ i, j }); }
			// if (air_que.empty() && map[i][j] == 0) { air_que.push({ i, j }); }
		}
	}
	// 테두리엔 얼음이 없다는 가정하
	air_que.push({ 0, 0 });
	map[0][0] = 2;
}

// solution
int solve() {
	int time = 0;

	// 1. 외부, 내부 공기 구분 & map change 
	Floodfill();

	while (!ice_que.empty()) {
		// 2. 시간의 흐름
		time++;
		// 3. 얼음 조정
		BFS();
		int debug2 = 0;
		// 4. 공기 확산 & map change
		Floodfill();
		int debug3 = 0;
	}

	return time;
}

// Flood fill
void Floodfill() {

	while (!air_que.empty()) {
		str now = air_que.front();
		air_que.pop();
		used[now.y][now.x] = 1;
		map[now.y][now.x] = 2;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dirY[i];
			int nx = now.x + dirX[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] == 1) continue;
			if (used[ny][nx] == 1) continue;

			used[ny][nx] = 1;

			air_que.push({ ny, nx });
			map[ny][nx] = 2;
		}
	}

}

// Breadth-First Search	(ice melts)
void BFS() {
	queue<str> tmp_que;

	while (!ice_que.empty()) {
		str now = ice_que.front();
		ice_que.pop();

		int cnt = 0;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dirY[i];
			int nx = now.x + dirX[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

			if (map[ny][nx] == 2) cnt++;

			if (cnt > 1) {
				air_que.push({ now.y, now.x });
				// chg_que.push({ now.y, now.x });
				break;
			}
		}

		if (cnt < 2) { tmp_que.push({ now.y, now.x }); }
	}

	/*
	while (!chg_que.empty()) {
		str now = chg_que.front();
		chg_que.pop();
		map[now.y][now.x] = 2;
	} */

	ice_que = tmp_que;
}