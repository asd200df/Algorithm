// 택배 마스터 광우 
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N, M, K; // 레일 갯수, 바구니 무게, 시행 횟수
int arr[11];
int used[11];
vector<int> vec;
int mini = 21e8;

// Function
void input();
void solve();
void DFS(int now);
int sum();

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
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

// solution
void solve() {
	DFS(0);

	cout << mini << "\n";
}

// DFS search
void DFS(int now) {
	if (now == N) {
		// to do something ...
		int data = sum();
		if (data < mini) mini = data;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		vec.push_back(arr[i]);
		DFS(now + 1);
		vec.pop_back();
		used[i] = 0;
	}
}

// calculator
int sum() {
	int cnt = K;
	int ret = 0;
	int start = 0;

	while (cnt--) {
		int tmp = 0;
		for (int i = start; i < start + N; i++) {
			int idx = i % N;
			tmp += vec[idx];
			if (tmp > M) {
				ret += (tmp - vec[idx]);
				start = idx;
				break;
			}
		}
	}

	return ret;
}