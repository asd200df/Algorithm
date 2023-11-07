// 최솟값 만들기
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
int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater());

	int sum = 0;
	for (int i = 0; i < A.size(); i++) {
		int a = A[i];
		int b = B[i];

		sum += a * b;
	}

	answer = sum;

	return answer;
}
