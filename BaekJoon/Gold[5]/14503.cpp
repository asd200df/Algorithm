// �κ� û�ұ� (14503) Gold[5]
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
int N, M; // <= 50
int cnt;
int start_y, start_x, start_d;
int maps[55][55];
int dir[2][4] = { {-1, 0, 1, 0}, {0, 1, 0, -1} }; // 0 ��, 1 ��, 2 ��, 3 ��

// Function
void input();
void solve();
void clean(int ny, int nx);
int navi(int ny, int nx);

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

	cin >> start_y >> start_x >> start_d;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}
}

// solution
void solve() {

	// now (x, y, direct)
	int ny = start_y;
	int nx = start_x;
	int nd = start_d;

	// simulation
	while (true) {
		int debug = 0;

		// 1. ���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�
		if (maps[ny][nx] == 0) { clean(ny, nx); }

		debug = 1;

		// ���� ĭ�� �ֺ� 4ĭ searching ...
		int chk = navi(ny, nx);

		// 2. ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� ���� ���,
		if (chk == 0) {
			int ntd = (nd + 2) % 4; // �ٶ󺸴� ������ �ݴ� ����

			int nty = ny + dir[0][ntd];
			int ntx = nx + dir[1][ntd];

			// 2-1 �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �� �ִٸ� �� ĭ �����ϰ� 1������
			if (maps[nty][ntx] != 1) {
				ny = nty;
				nx = ntx;
				continue;
			}

			// ��� ���� 1 (������ �Ѿ�� ���)
			// if (nty < 0 || nty >= N || ntx < 0 || ntx >= M) { continue; }

			// 2-2 �ٶ󺸴� ������ ���� ĭ�� ���̶� ������ �� ���ٸ� �۵� ����
			if (maps[nty][ntx] == 1) { break; }
		}

		// 3. ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ� ���,
		else { // chk != 0 

			// 3-1 �ݽð� �������� 90�� ȸ���Ѵ�
			nd = nd - 1;
			if (nd == -1) { nd = 3; }

			// 3-2 �ٶ󺸴� ������ �������� ���� ĭ�� û�ҵ��� ���� ��ĭ�� ��� �� ĭ �����Ѵ�
			int nty = ny + dir[0][nd];
			int ntx = nx + dir[1][nd];
			if (maps[nty][ntx] == 0) {
				ny = nty;
				nx = ntx;
			}

			// 3-3 1������ ���ư���
			continue;
		}

	}

	// print result !
	cout << cnt << "\n";
}

// cleaning
void clean(int ny, int nx) { 
	maps[ny][nx] = 9; 
	cnt++;
}

// Navigation
int navi(int ny, int nx) {
	int c = 0;

	for (int i = 0; i < 4; i++) {
		int nty = ny + dir[0][i];
		int ntx = nx + dir[1][i];

		if (nty < 0 || nty >= N || ntx < 0 || ntx >= M) { continue; }

		if (maps[nty][ntx] == 0) { c++; }
	}

	return c;
}