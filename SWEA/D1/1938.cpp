// 아주 간단한 계산기
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

	int a, b;
	cin >> a >> b;

	cout << a + b << "\n";
	cout << a - b << "\n";
	cout << a * b << "\n";
	cout << a / b << "\n";

	return 0;
}
