// 몫과 나머지 출력하기
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int a, b;

		cin >> a >> b;

		cout << "#" << tc + 1  << " " << a / b 
			<< " " << a % b << "\n";
	}

	return 0;
}