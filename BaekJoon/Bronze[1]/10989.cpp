// �� �����ϱ� 3 (10989) Bronze[1]
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
int N; // <= 10,000,000
int arr[10001]; // ���� �� �ִ� ���ڰ� 10,000 �����ϱ�

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
	cin >> N;
	
	int inp;
	for (int i = 0; i < N; i++) { 
		cin >> inp;
		arr[inp] += 1;
	}

	// sort(vec.begin(), vec.end());

	for (int i = 0; i < 10001; i++) { // ���� �� �ִ� ���ڱ��� 
		if (arr[i] == 0) { continue; }

		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}
}

// �� �׳� sort ����ϸ� �޸� �ʰ� ���� ������
//		count ���� ����ؾ� �� 