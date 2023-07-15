// 회전하는 큐 (1021) Silver[3]
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

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int N, M;

// Function
void insol();

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N >> M;

	deque<int> dq;
	for (int i = 1; i <= N; i++) { dq.push_back(i); }
	
	int inp = 0;
	vector<int> vec;
	for (int i = 0; i < M; i++) {
		cin >> inp;
		vec.push_back(inp);
	}

	int result = 0;
	int target = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	deque<int> temp_dq1;
	deque<int> temp_dq2;
	for (int i = 0; i < vec.size(); i++) {
		cnt1 = cnt2 = 0;
		temp_dq1 = temp_dq2 = dq;
		target = vec[i];

		while (true) { // 정방향
			int now = temp_dq1.front();
			temp_dq1.pop_front();
			if (now == target) { break; }
			cnt1++;
			temp_dq1.push_back(now);
		}

		while (true) { // 역방향
			int now = temp_dq2.back();
			temp_dq2.pop_back();
			temp_dq2.push_front(now);
			cnt2++;
			if (now == target) { 
				temp_dq2.pop_front();
				break; 
			}
		}

		if (cnt1 < cnt2) {
			dq = temp_dq1;
			result += cnt1;
		}
		else {
			dq = temp_dq2;
			result += cnt2;
		}
	}

	cout << result << "\n";
}