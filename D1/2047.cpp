// 신문 헤드라인
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
	string str, ret;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') cout << char(str[i] - 32);
		else cout << str[i];
	} cout << endl;
	// - 'a' + 'A'
	return 0;
}
