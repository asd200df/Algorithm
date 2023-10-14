// 기지국 설치
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

// solve
int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int count = 0;

	// sort
	sort(stations.begin(), stations.end());

	// Exception
	bool flag = true;
	if (n == stations.size()) { flag = false; }

	// processor
	int pre = 0;
	int cover = 1 + (w * 2);
	for (int i = 0; i < stations.size(); i++) {
		int left = stations[i] - w;
		int right = stations[i] + w;

		int diff = (left - 1) - pre;

		pre = right;

		while (diff > 0) {
			diff -= cover;
			count++;
		}
	}

	// double check
	if (pre < n) {
		int diff2 = n - pre;
		while (diff2 > 0) {
			diff2 -= cover;
			count++;
		}
	}

	// update
	if (flag) { answer = count; }
	else { answer = 0; }

	// return result !
	return answer;
}