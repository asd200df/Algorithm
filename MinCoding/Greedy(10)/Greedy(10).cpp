// 알고리즘탑 >> Greedy >> 전구 켜기
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int bulb_N, btn_N, link, flag = 0;
int state[11], minimum = 21e8, used[11];
vector<vector<int>> vec(11);

bool isValid() {
	for (int i = 0; i < bulb_N; i++) {
		if (state[i] == 0) {
			return false;
		}
	}
	return true;
}

void Toggle(int pb) {
	for (int i = 0; i < vec[pb].size(); i++) {
		int index = vec[pb][i] - 1;
		state[index] = abs(state[index] - 1);
	}
}

void DFS(int turn, int limit, int cnt) {
	if (turn == limit) {
		if (isValid()) {
			if (cnt < minimum) minimum = cnt;
			flag = 1;
		}
		return;
	}
	for (int push = 0; push < 2; push++) {
		// none
		if (push == 0) {
			for (int btn = 0; btn < btn_N; btn++) { 
				if (used[btn] == 1) continue;
				used[btn] = 1;
				DFS(turn + 1, limit, cnt);
				if (flag == 1) return;
				used[btn] = 0;
			}
		}
		// pushed
		else { // push == 1
			for (int btn = 0; btn < btn_N; btn++) {
				if (used[btn] == 1) continue;
				used[btn] = 1;
				Toggle(btn);
				DFS(turn + 1, limit, cnt + 1);
				if (flag == 1) return;
				Toggle(btn);
				used[btn] = 0;
			}
		}
	}
}

int solve() {
	if (isValid()) { return 0; }
	else { 
		for (int limit = 1; limit <= btn_N; limit++) {
			DFS(0, limit, 0);
			if (flag == 1) break;
		}
	}
	return minimum;
}

void input() {
	cin >> bulb_N >> btn_N >> link;
	for (int i = 0; i < bulb_N; i++) { cin >> state[i]; }
	for (int i = 0; i < btn_N; i++) {
		for (int j = 0; j < link; j++) {
			int tmp;
			cin >> tmp;
			vec[i].push_back(tmp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input(); // input func call

	int result = solve(); // solve func call

	cout << result << "\n";

	return 0;
}
