// 무인도 여행
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// global
int n, m;
int mapi[101][101];
bool used[101][101];
int dir[2][4] = { { -1, 0, 1, 0 }, { 0, -1, 0, 1 } };
typedef struct { int y, x; }node;
vector<node> island;

// function
int BFS(node ins);

// solve
vector<int> solution(vector<string> maps) {
	vector<int> answer;

	// initialization
	n = maps.size();
	m = maps[0].size();

	// convert
	bool flag = false;
	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[i].size(); j++) {
			char now = maps[i][j];
			if (now == 'X') { mapi[i][j] = 0; }
			else {
				flag = true;
				mapi[i][j] = now - '0';
				island.push_back({ i, j });
			}
		}
	}

	// Exception
	if (flag == false) {
		answer.push_back(-1);
		return answer;
	}

	// func call
	vector<int> ret;
	for (int i = 0; i < island.size(); i++) {
		node ins = island[i];
		if (used[ins.y][ins.x]) { continue; }
		ret.push_back(BFS(ins));
	}

	// sort
	sort(ret.begin(), ret.end());

	/* debug
	for(int i = 0; i < ret.size(); i++){
		cout << ret[i] << " ";
	} cout << "\n";
	*/

	// update
	answer = ret;

	// return result
	return answer;
}

// Breadth-First Search
int BFS(node ins) {
	int total = 0;
	queue<node> que;
	que.push(ins);
	used[ins.y][ins.x] = true;
	total += mapi[ins.y][ins.x];

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[0][i];
			int nx = now.x + dir[1][i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) { continue; }
			if (used[ny][nx]) { continue; }
			if (mapi[ny][nx] == 0) { continue; }

			used[ny][nx] = true;

			total += mapi[ny][nx];
			que.push({ ny, nx });
		}
	}

	return total;
}