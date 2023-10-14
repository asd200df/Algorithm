// 단속카메라
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

// compare
bool compare(vector<int> a, vector<int> b) {
	if (a[1] < b[1]) { return true; }
	else { return false; }
}

// solve
int solution(vector<vector<int>> routes) {
	int answer = 0;

	// sort
	sort(routes.begin(), routes.end(), compare);

	/* debug
	for(int i = 0; i < routes.size(); i++){
		for(int j = 0; j < routes[i].size(); j++){
			cout << routes[i][j] << " ";
		} cout << "\n";
	} */

	// processor
	int count = 0;
	int camera = -21e8;
	int in, out;
	for (int i = 0; i < routes.size(); i++) {
		for (int j = 0; j < routes[i].size(); j++) {
			if (j == 0) { in = routes[i][j]; }
			else { out = routes[i][j]; }
		}

		if (camera >= in) { continue; }
		else {
			count++;
			camera = out;
		}
	}

	// update
	answer = count;

	// return result !
	return answer;
}