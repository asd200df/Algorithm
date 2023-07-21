// ������ ��ġ (2110) Gold[4]
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
	int left = 1; // �Ÿ����� �ּ� 1�ϲ��ϱ� 1���� ����
	int right = town[N - 1];
	int mid, cnt, prefix, ret = 0;

	while (left <= right) {
		mid = (left + right) / 2; // distance

		cnt = 1; // �� ó�� ���� �ְ� ������ 
		prefix = town[0]; // �� ó�� �� �ְ� ������ 2
		for (int i = 1; i < N; i++) { // check
			if (abs(town[i] - prefix) >= mid) { // mid �Ÿ��� ��ġ ���� ��
				cnt++;
				prefix = town[i];
			}
		}

		// �°� ��ġ �� �� �ְų� �� ���� ��ġ �� ���� �־�
		// ��Ȯ�� �̾߱� �ϸ� �� ���� ���� ��ġ �� �� �־�
		// �׷��Ƿ� �� ���� ���� ��ġ �� �� �־ ����
		if (cnt >= C) { 
			ret = mid;
			left = mid + 1;
		} 
		else { // cnt < C // �� ��ġ ���߾� 
			right = mid - 1;
		}

	}

	return ret;
}