// [21년 재직자 대회 예선] 비밀 메뉴
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
int M;  // 비밀 메뉴 조작법의 수
int N;  // 사용자가 누른 버튼의 수
int K;  // 버튼의 수
int secret[101];  // secret num
int custom[101];  // customer num

// Function
void input();
int solve();
bool isValid(int idx);

// MAIN
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	int result = solve();

	if (result == 0) cout << "normal\n";
	else cout << "secret\n";

	return 0;
}

// input
void input() {
	cin >> M >> N >> K;
	for (int i = 0; i < M; i++) { cin >> secret[i]; }
	for (int i = 0; i < N; i++) { cin >> custom[i]; }
}

// solution
int solve() {
	int flag = 0;

	for (int i = 0; i < N; i++) {
		if (custom[i] != secret[0]) continue;
		if (isValid(i)) flag = 1;
	}

	return flag;
}

// valid check
bool isValid(int idx) {
	int cnt = 0;
	int steady = 1;

	for (int i = 0; i < M; i++) {
		if (custom[idx + i] == secret[i]) {
			cnt++;
			steady = 1;
		}
		else { steady = 0; }

		if (steady = 0) cnt = 0; // 연속성이 없으면 cnt 초기화 
		if (cnt == M) return true; // 찾았을 경우
	}

	return false; // 못 찾은 경우
}