// 더블더블
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
// #include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, ret = 1;
	cin >> N;

	for (int i = 0; i <= N; i++) {
		cout << ret << " ";
		ret = ret * 2;
	} cout << "\n";

	return 0;
}