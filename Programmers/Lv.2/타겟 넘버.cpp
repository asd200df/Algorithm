// Å¸°Ù ³Ñ¹ö
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
int cnt, tar;
vector<int> n;

// function
void DFS(int now, int sum);

// solve
int solution(vector<int> numbers, int target) {
	int answer = 0;

	// parsing
	tar = target;
	n = numbers;

	// func call
	DFS(0, 0);

	// update result
	answer = cnt;

	// return result !
	return answer;
}

// Depth-First Search
void DFS(int now, int sum) {
	if (now == n.size()) {
		if (sum == tar) { cnt++; }
		return;
	}

	for (int type = 1; type <= 2; type++) { // 1 = +, 2 = - 
		if (type == 1) { // +
			DFS(now + 1, sum + n[now]);
		}
		else { // type == 2 // -
			DFS(now + 1, sum - n[now]);
		}
	}
}