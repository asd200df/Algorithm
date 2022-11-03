// N¡Ÿ µ°º¿
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

	for (int i = 1; i <= N; i++) { ret += i; }
	cout << ret << endl;

	return 0;
}