// [21�� ������ ��ȸ ����] ��� �޴�
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
int M;  // ��� �޴� ���۹��� ��
int N;  // ����ڰ� ���� ��ư�� ��
int K;  // ��ư�� ��
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

		if (steady = 0) cnt = 0; // ���Ӽ��� ������ cnt �ʱ�ȭ 
		if (cnt == M) return true; // ã���� ���
	}

	return false; // �� ã�� ���
}