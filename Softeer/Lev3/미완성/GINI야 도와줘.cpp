// GINI具 档客拎 
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
char map[51][51];6
int R, C;
int dirY[] = { 0, 0, -1, 1 };
int dirX[] = { -1, 1, 0, 0 };
typedef struct {
	int y, x;
	int cnt;
}str;
queue<str> R_que;
queue<str> E_que;
int result = 0;

// Function
void input();
int solve();
queue<str> Rain(queue<str> Rq);
queue<str> Ego(queue<str> Eq);
void MapChange(queue<str> change_q, char ch);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	int ret = solve();

	if (ret <= 0) cout << "FAIL\n";
	else cout << ret << "\n";

	return 0;
}

// input
void input() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') { R_que.push({ i, j, 0 }); }
			if (map[i][j] == 'W') { E_que.push({ i, j, 0 }); }
		}
	}
}

// solution
int solve() {

	while (!E_que.empty()) {
		R_que = Rain(R_que);
		MapChange(R_que, '*');
		E_que = Ego(E_que);
		if (result != 0) { break; }
		MapChange(E_que, 'w');
	}

	return result;
}

// map change function
void MapChange(queue<str> change_q, char ch) {
	while (!change_q.empty()) {
		str tmp = change_q.front();
		change_q.pop();

		int ny = tmp.y;
		int nx = tmp.x;

		map[ny][nx] = ch;
	}
}

// Rain que function
queue<str> Rain(queue<str> Rq) {
	queue<str> tmp_q;

	str tmp_str;

	while (!Rq.empty()) {
		tmp_str = Rq.front();
		Rq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = tmp_str.y + dirY[i];
			int nx = tmp_str.x + dirX[i];

			if (ny > R || ny < 0 || nx > C || nx < 0) continue;
			if (map[ny][nx] == 'X' || map[ny][nx] == 'H' || map[ny][nx] == 'W' || map[ny][nx] == '*') continue;
			tmp_q.push({ ny, nx, tmp_str.cnt + 1 });
		}
	}

	return tmp_q;
}

// Ego que function
queue<str> Ego(queue<str> Eq) {
	queue<str> tmp_q;

	str tmp_str;

	while (!Eq.empty()) {
		tmp_str = Eq.front();
		Eq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = tmp_str.y + dirY[i];
			int nx = tmp_str.x + dirX[i];

			if (ny > R || ny < 0 || nx > C || nx < 0) continue;
			if (map[ny][nx] == 'X' || map[ny][nx] == 'W' || map[ny][nx] == '*' || map[ny][nx] == 'w') continue;

			if (map[ny][nx] == 'H') {
				result = tmp_str.cnt + 1;
				break;
			}

			tmp_q.push({ ny, nx, tmp_str.cnt + 1 });
		}

		if (result != 0) break;
	}

	return tmp_q;
}


/* GINI具 档客拎 
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

*/