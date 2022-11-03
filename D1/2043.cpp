// 서랍의 비밀번호
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

	int N1, N2, cnt = 0;
	cin >> N1 >> N2;

	for (int i = N2; i < N1; i++) { cnt++; }
	cout << cnt << "\n";

	return 0;
}

