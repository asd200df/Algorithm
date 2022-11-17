// 알파벳을 숫자로 변환
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

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		cout << int(str[i] - 64) << " ";
	} cout << "\n";

	return 0;
}
