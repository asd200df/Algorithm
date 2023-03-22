// GINIæﬂ µµøÕ¡‡ 
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int R, C;
int flag = 0;
int ti = 0;
char map[52][52];
int directY[] = { 0, 0, -1, 1 };
int directX[] = { -1, 1, 0, 0 };
typedef struct {
	int y, x;
} str;
queue<str> rain_que;
queue<str> ego_que;

// Function
void input();
int solve();
queue<str> rain();
queue<str> ego();
void MapChange(queue<str> que, int type);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	int result = solve();

	if (result == -1) cout << "FAIL\n";
	else cout << result << "\n";

	return 0;
}

// input
void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) { cin >> map[i]; }
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '*') { rain_que.push({ i, j }); }
			if (map[i][j] == 'W') { ego_que.push({ i, j }); }
		}
	}
}

// solution
int solve() {

	while (1) {
		cout << "===================\n";
		for (int i = 0; i < R; ++i) {
			cout << map[i] << '\n';
		}
		cout << "===================\n";
		ti++;
		rain_que = rain();
		MapChange(rain_que, 1);
		ego_que = ego();
		MapChange(ego_que, 2);
		if (ego_que.size() == 0 || flag == 1) break;
	}

	if (flag == 1) return ti;
	else return -1;
}

// Rain Floodfill
queue<str> rain() {
	queue<str> tmp;

	while (!rain_que.empty()) {
		str tmp_str = rain_que.front();
		rain_que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = tmp_str.y + directY[i];
			int nx = tmp_str.x + directX[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (map[ny][nx] == 'X') continue;
			if (map[ny][nx] == 'H') continue;

			tmp.push({ ny, nx });
		}
	}

	return tmp;
}

// Ego Floodfill
queue<str> ego() {
	queue<str> tmp;

	while (!ego_que.empty()) {
		str tmp_str = ego_que.front();
		ego_que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = tmp_str.y + directY[i];
			int nx = tmp_str.x + directX[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (map[ny][nx] == 'X') continue;
			if (map[ny][nx] == '*') continue;
			if (map[ny][nx] == 'U') continue;

			if (map[ny][nx] == 'H') {
				flag = 1;
				continue;
			}

			tmp.push({ ny, nx });
		}
	}

	return tmp;
}

// map change
void MapChange(queue<str> que, int type) {
	char ch = ' ';

	if (type == 1) ch = '*';
	if (type == 2) ch = 'U';

	while (!que.empty()) {
		str str_tmp = que.front();
		que.pop();

		map[str_tmp.y][str_tmp.x] = ch;
	}

}


