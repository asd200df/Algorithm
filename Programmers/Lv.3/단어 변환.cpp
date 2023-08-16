// 단어 변환
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
int mini = 21e8;
int used[55];
string tar;
vector<string> vec;

// function
void DFS(int cnt, string now);

// solve
int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	// first check
	bool flag = false;
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == target) { flag = true; }
	}
	if (!flag) { return 0; }

	// convert (local to global)
	vec = words;
	tar = target;

	// func call
	DFS(0, begin);

	// result update
	if (mini == 21e8) { answer = 0; }
	else { answer = mini; }

	// return result !
	return answer;
}

// Depth-First Search
void DFS(int cnt, string now) {
	// cout << tar << " == " << now << " " << cnt << "\n";
	if (now == tar) {
		mini = min(mini, cnt);
		return;
	}

	for (int i = 0; i < vec.size(); i++) {
		if (used[i] == 1) { continue; }

		string next = vec[i];

		int check = 0;
		for (int k = 0; k < now.size(); k++) {
			if (now[k] != next[k]) { check++; }
		}

		if (check > 1) { continue; }

		used[i] = 1;
		DFS(cnt + 1, next);
		used[i] = 0;
	}
}