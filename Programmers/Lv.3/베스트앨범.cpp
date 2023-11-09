// º£½ºÆ®¾Ù¹ü
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
typedef struct {
	string s;
	int n;
}node;
typedef struct {
	string s;
	int i, n;
}node2;

// compare
bool compare(node a, node b) {
	if (a.n > b.n) { return true; }
	else { return false; }
}
bool compare2(node2 a, node2 b) {
	if (a.n > b.n) { return true; }
	else if (a.n == b.n) { return a.i < b.i; }
	else { return false; }
}

// solve
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	// initialization
	unordered_map<string, int> gnr;
	int lim = genres.size();
	vector<node> gvec;
	vector<node2> pvec;

	// parsing
	for (int i = 0; i < lim; i++) {
		string g = genres[i];
		int p = plays[i];

		// cout << g << " " << p << "\n";

		pvec.push_back({ g, i, p });
		gnr[g] += p;
	}

	// convert
	for (auto iter : gnr) { gvec.push_back({ iter.first, iter.second }); }

	// vector sort
	sort(gvec.begin(), gvec.end(), compare);
	sort(pvec.begin(), pvec.end(), compare2);

	// processor
	for (int i = 0; i < gvec.size(); i++) {
		string ng = gvec[i].s;

		int cnt = 0;
		for (int i = 0; i < pvec.size(); i++) {
			if (pvec[i].s != ng) { continue; }
			if (cnt == 2) { break; }

			int nidx = pvec[i].i;

			answer.push_back(nidx);
			cnt++;
		}
	}

	// return result !
	return answer;
}