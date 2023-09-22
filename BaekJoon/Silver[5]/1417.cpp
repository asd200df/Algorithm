// 국회의원 선거 (1417) Silver[5]
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
int N;

// Function
void insolve();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insolve();

	return 0;
}

// input && solution
void insolve() {
	int target = 0;

	cin >> N;

	priority_queue<int> pq;

	cin >> target;

	if (N == 1) { // 단일 후보의 경우
		cout << "0\n"; 
		return;
	}

	int inp;
	for (int i = 1; i < N; i++) {
		cin >> inp;
		pq.push(inp);
	}

	bool flag = true;
	int cnt = 0;
	while (flag) {

		if (target <= pq.top()) {
			int temp = pq.top();
			pq.pop();
			pq.push(temp - 1);
			target++;
			cnt++;
		}
		else { flag = false; }

	}

	cout << cnt << "\n";
}