// 자릿수 더하기
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, ret = 0;
	cin >> N;

	while (1) {
		ret += N % 10;
		N = N / 10;
		if (N == 0) break;
	} cout << ret << "\n";

	return 0;
}
