// 단어 공부 (1157) Bronze[1]
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int cnt[128];

// Function
void insol();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insol();

	return 0;
}

// input && solution
void insol() {
	string inp;
	int maxi = -21e8;

	cin >> inp;

	for (int i = 0; i < inp.size(); i++) {
		if (inp[i] <= 'Z' && inp[i] >= 'A') {
			cnt[inp[i] + 32]++;
			maxi = max(maxi, cnt[inp[i] + 32]);
		}
		else {
			cnt[inp[i]]++;
			maxi = max(maxi, cnt[inp[i]]);
		}
	}

	string ret;
	bool flag = false;
	int flag_cnt = 0;
	for (int i = 97; i <= 122; i++) {
		if (cnt[i] == maxi) {
			ret = i - 32;
			flag_cnt++;
		}
		if (flag_cnt > 1) { flag = true; }
	}

	if (flag) { cout << "?\n"; }
	else { cout << ret << "\n";}
}