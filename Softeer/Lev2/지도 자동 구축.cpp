// ���� �ڵ� ����
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

// MAIN
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*  ��Ģ ã�ƺ���

		1. ���� �� ����
		4 >> 9 >> 25 >> 81

		2. ������ ���� ������ ���� ���� ��
		2 3 5 9

		3. 2 3 5 9�� ��Ģ
		�� �� ������ x2 -1 �� ����
	*/

	int N, result, tmp = 2;
	cin >> N;

	// ��Ģ ����
	for (int i = 0; i < N; i++) { tmp = (tmp * 2) - 1; }

	// �����ϱ� 
	result = tmp * tmp;

	cout << result << "\n";

	return 0;
}