// 공유기 설치 (2110) Gold[4]
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
int N, C;
int town[200001];

// Function
void input();
void solve();
int BS();

// Main
int main(int argc, char** argv) {
	FastIO;

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) { cin >> town[i]; }
}

// solution
void solve() {
	int result = 0;

	// sort ASC
	sort(town, town + N);

	// Call binary search
	result = BS();

	// print result
	cout << result << "\n";
}

// Binary Search
int BS() {
	int left = 1; // 거리차가 최소 1일꺼니까 1부터 시작
	int right = town[N - 1];
	int mid, cnt, prefix, ret = 0;

	while (left <= right) {
		mid = (left + right) / 2; // distance

		cnt = 1; // 맨 처음 집은 넣고 시작해 
		prefix = town[0]; // 맨 처음 집 넣고 시작해 2
		for (int i = 1; i < N; i++) { // check
			if (abs(town[i] - prefix) >= mid) { // mid 거리로 설치 했을 때
				cnt++;
				prefix = town[i];
			}
		}

		// 맞게 설치 할 수 있거나 더 많이 설치 할 수도 있어
		// 정확히 이야기 하면 더 많은 곳에 설치 할 수 있어
		// 그러므로 더 많은 곳에 설치 할 수 있어도 갱신
		if (cnt >= C) { 
			ret = mid;
			left = mid + 1;
		} 
		else { // cnt < C // 다 설치 못했어 
			right = mid - 1;
		}

	}

	return ret;
}