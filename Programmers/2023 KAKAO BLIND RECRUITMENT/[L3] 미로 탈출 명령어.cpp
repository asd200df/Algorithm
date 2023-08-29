// 미로 탈출 명령어
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// global
int N, M, esc_y, esc_x, K;
string path, ret;
int dir[2][4] = { { 1, 0, 0, -1 }, { 0, -1, 1, 0 } };
char cdir[4] = { 'd', 'l', 'r', 'u' };
bool flag = false;

// function
void DFS(int cnt, int now_y, int now_x);

// solve
string solution(int n, int m, int x, int y, int r, int c, int k) {
	string answer = "";

	// convert
	N = n;
	M = m;
	esc_y = r;
	esc_x = c;
	K = k;

	// DFS func call
	DFS(0, x, y);

	// sort
	// sort(vec.begin(), vec.end());

	/* debug
	string tt;
	for(int i = 0; i < vec.size(); i++){
		if(i != 0) { continue; }
		answer = vec[0];
	} */

	// update
	if (flag) { answer = ret; }
	else { answer = "impossible"; }

	// return result !
	return answer;
}

// Depth-First Search
void DFS(int cnt, int now_y, int now_x) {
	if (flag) { return; }

	if (cnt == K) {
		if (now_y == esc_y && now_x == esc_x) {
			flag = true;
			ret = path;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = now_y + dir[0][i];
		int nx = now_x + dir[1][i];
		int diff = abs(ny - esc_y) + abs(nx - esc_x);

		if (ny <= 0 || ny > N || nx <= 0 || nx > M) { continue; }
		if (((K - (cnt + 1))) < diff) { continue; }
		if (((K - (cnt + 1)) - diff) % 2 == 1) { continue; }

		path += cdir[i];
		DFS(cnt + 1, ny, nx);
		if (flag) { break; }
		path.pop_back();
	}
}