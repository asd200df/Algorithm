// ����� (2108) Silver[3]
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
	int sum = 0, cntmax = 0, val = 0;
	cin >> N;
	vector<int> v(N); // ���� ������ ����
	vector<int> cnt(8001); // �ֺ��� ����� ����

	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		sum += v[i]; // ���� ���

		cnt[v[i] + 4000]++; // �ֺ� ����
	}

	sort(v.begin(), v.end());

	// �ֺ� �� ���� ���� ��
	for (int i = 0; i <= 8000; ++i) {
		if (cnt[i] > cntmax) {
			cntmax = cnt[i];
			val = i;
		}
	}

	// �� ��°�� ���� �ֺ��� ���ؾ� �Ѵ�.
	// �̹� ������ ���� ���� �ֺ��� ã�Ƴ����Ƿ� val + 1���� Ž���Ѵ�.
	for (int i = val + 1; i <= 8000; ++i) {
		if (cnt[i] == cntmax) {
			val = i;
			break;
		}
	}
	sum = round(double(sum) / N);

	cout << sum << "\n"; // ������, round(double(sum) / N)�� �״�� ���� -0���� ��µ�
	cout << v[(N - 1) / 2] << "\n"; // �߾Ӱ�
	cout << val - 4000 << "\n"; // �ֺ�
	cout << v[N - 1] - v[0]; // �ִ� �ּ� ����

}