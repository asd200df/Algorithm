// �κ��� ������ ��� [HSAT 1ȸ ���� �ڵ� ������ ����]
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
int H, W; // <= 25
char map[27][27];
char dir_mark[4] = { '^', '>', 'v', '<' };
int dir[2][4] = { { -1, 0, 1, 0 }, { 0, 1, 0, -1 } };

// Function
void input();
void solve();
int FD(int y, int x, int type);

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
	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
}

// solution
void solve() {
	int start_y, start_x;

	// ����� ã��
	bool flag = false;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == '.') { continue; }
			if (FD(i, j, 1) == -1) { continue; }

			start_y = i;
			start_x = j;
			flag = true;
			break;
		}
		if (flag) { break; }
	}

	// ��� ���� ã��
	char first_mark;
	int idx = FD(start_y, start_x, 2);
	first_mark = dir_mark[idx];

	// ������� ��� ���� ����ϱ�
	cout << start_y + 1 << " " << start_x + 1 << "\n";
	cout << first_mark << "\n";

	// ����
	int now_y = start_y;
	int now_x = start_x;
	int prefix_dir = idx;
	int post_dir = 0;
	map[now_y][now_x] = '.';
	while (true) { // ���� ��ȯ
		while (true) { // ���� (2ĭ��)
			int ny = now_y + dir[0][prefix_dir];
			int nx = now_x + dir[1][prefix_dir];
			int ny2 = now_y + (dir[0][prefix_dir] * 2);
			int nx2 = now_x + (dir[1][prefix_dir] * 2);

			if (ny2 < 0 || ny2 >= H || nx2 < 0 || nx2 >= W) { break; }
			if (map[ny][nx] == '.') { break; }
			if (map[ny2][nx2] == '.') { break; }

			map[ny][nx] = '.';
			map[ny2][nx2] = '.';

			now_y = ny2;
			now_x = nx2;

			cout << "A";
		}

		post_dir = FD(now_y, now_x, 2);

		// �� �̻� �� ���� �� 
		if (post_dir == -1) { break; }

		int right = (prefix_dir + 1) % 4;
		int left = (prefix_dir + 3) % 4;
		if (post_dir == right) { // ��ȸ��
			cout << "R";
		}
		else if (post_dir == left) { // ��ȸ��
			cout << "L";
		}

		prefix_dir = post_dir;
	}

	cout << "\n";
}

// Find Direction
int FD(int y, int x, int type) {
	int cnt = 0;
	int find_dir = 0;

	// 4 dir search
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[0][i];
		int nx = x + dir[1][i];

		if (ny < 0 || ny >= H || nx < 0 || nx >= W) { continue; }
		if (map[ny][nx] == '.') { continue; }

		find_dir = i;
		cnt++;
	}

	if (type == 1) {
		if (cnt == 1) { return 1; } // ����� �ĺ�
		else { return -1; } // ����� �ƴ� ����
	}

	// type == 2
	if (cnt == 0) { return -1; } // �� �̻� �� ���� ���� ��
	else { return find_dir; } // �� �� ���� �� �� ���� return
}