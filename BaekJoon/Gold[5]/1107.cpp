// ������ (1107) Gold[5]
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
int N; // <= 500,000
int M; // <= 10
int check_ret;
int cnt;
bool remote[10];

// Function
void input();
void solve();
bool check(int now, int tar, int c);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N >> M;
	int inp;
	for (int i = 0; i < M; i++) {
		cin >> inp;
		remote[inp] = true;
	}
}

// solution
void solve() {
	int result = 0;

	// Exception
	string t = to_string(N);
	if(N == 100) { // ���ϴ� ���� �̹� ���� ��
		cout << "0\n";
		return;
	}
	else if (M == 0) { // ���峭 ��ư�� ���� ��
		if (t.size() < abs(100 - N)) {
			cout << t.size() << "\n";
			return;
		}
		else {
			cout << abs(100 - N) << "\n";
			return;
		}
	}
	else if (M == 10) { // ��� ��ư ����
		cout << abs(100 - N) << "\n";
		return;
	}
	else if (t.size() > abs(100 - N)) { // +, - �� ���°� �� ���� ��
		cout << abs(100 - N) << "\n";
		return;
	}

	// Searching ...
	int now = 100;
	int target = N;
	int cnt = 0;
	while (true) {

		// ��ǥ ä�� �޼�
		if (target == 100) { break; }

		if (check(now, target, cnt)) { // ��ȣ ������ ����
			result += check_ret;
			break;
		}
		else { // +, - ������ �̵��ϱ�
			cnt++;
			if ((target + cnt) == 100 || (target - cnt) == 100) {
				break;
			}
		}
	}

	result += cnt;

	if (result > abs(N - 100)) { result = abs(N - 100); }

	cout << result << "\n";
}

// valid check (��ȣ�� ������ �� �� �ִ°�)
bool check(int now, int tar, int c) {
	bool flag[2];
	int pt = tar + c;
	int mt = tar - c;

	string temp[2];
	temp[0] = to_string(pt);
	temp[1] = to_string(mt);
	for (int i = 0; i < 2; i++) {	
		flag[i] = true;
		for (int j = 0; j < temp[i].size(); j++) {
			int t = temp[i][j] - '0';

			if (remote[t]) {
				flag[i] = false;
				break;
			}
		}
	}
	
	if (flag[0] && flag[1]) {
		if (temp[0].size() < temp[1].size()) {
			check_ret = temp[0].size();
			return true;
		}
		else {
			check_ret = temp[1].size();
			return true;
		}
	}
	else if (flag[0]) {
		check_ret = temp[0].size();
		return true;
	}
	else if (flag[1]) {
		check_ret = temp[1].size();
		return true;
	}
	else {
		return false;
	}
}