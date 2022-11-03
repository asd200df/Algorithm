// 중간값 찾기
#include <iostream>
#include <string>
#include <cstring>
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

	int N, num[200];
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	} sort(num, num + N);

	cout << num[N / 2] << "\n";

	return 0;
}