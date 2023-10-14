// 최고의 집합
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
vector<int> solution(int n, int s) {
	vector<int> answer;

	int arr[10001];
	int div = s / n;
	int mod = s % n;
	// if) s 15, n 4 / div 3 / mod 3 / 4 4 4 3

	if (div == 0) {
		answer.push_back(-1);
	}
	else if (mod == 0) { for (int i = 0; i < n; i++) { answer.push_back(div); } }
	else {
		for (int i = 0; i < n; i++) { arr[i] = div; }
		for (int i = 0; i < mod; i++) { arr[i % n] += 1; }
		sort(arr, arr + n);
		for (int i = 0; i < n; i++) { answer.push_back(arr[i]); }
	}

	return answer;
}