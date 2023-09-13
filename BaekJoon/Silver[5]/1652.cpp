// 누울 자리를 찾아라 (1652) Silver[5]
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
int N; // <= 100
char maps[101][101];
bool used[2][101][101];
typedef struct { int y, x; }node;
vector<node> vec;

// Function
void input();
void solve();
bool BFS(int type, node ins);

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
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == '.') { vec.push_back({ i, j }); }
		}
	}
}

// solution
void solve() {
	int row_cnt = 0;
	int col_cnt = 0;

	for (int i = 0; i < vec.size(); i++) {
		node ins = vec[i];

		for (int type = 0; type <= 1; type++) {
			if (used[type][ins.y][ins.x] == true) { continue; }
		
			if (BFS(type, ins)) {
				if (type == 0) { row_cnt++; }
				else { col_cnt++; }
			}
		}
	} 

	cout << col_cnt << " " << row_cnt << "\n";
}

// Breadth-First Search
bool BFS(int type, node ins) {
	int count = 1;
	queue<node> que;
	que.push(ins);
	used[type][ins.y][ins.x] = true;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		int ny = now.y;
		int nx = now.x;

		if (type == 0) { // row
			ny++;
		}	
		else { // type == 1 // col
			nx++;
		}
		
		if (ny >= N || nx >= N) { continue; }
		if (used[type][ny][nx] == true) { continue; }
		if (maps[ny][nx] == 'X') { continue; }

		used[type][ny][nx] = true;
		que.push({ ny, nx });
		count++;
	}

	if (count >= 2) { return true; }
	else { return false; }
} 