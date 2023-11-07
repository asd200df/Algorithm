// ±Ö °í¸£±â
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
typedef struct { int num, cnt; } node;
unordered_map<int, int> um;
vector<node> vec;

// compare
bool compare(node a, node b) {
	if (a.cnt > b.cnt) { return true; }
	else { return false; }
}

// function
// -

// solve
int solution(int k, vector<int> tangerine) {
	int answer = 0;

	for (int i = 0; i < tangerine.size(); i++) {
		int now = tangerine[i];
		um[now]++;
	}

	for (auto iter : um) { vec.push_back({ iter.first, iter.second }); }

	sort(vec.begin(), vec.end(), compare);

	int kind = 0;
	int K = k;
	int idx = 0;
	while (K > 0) {
		K -= vec[idx++].cnt;
		kind++;
	}

	answer = kind;

	return answer;
}
