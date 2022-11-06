#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>

using namespace std;
int N, K[100001], acc[100001], maxi = 0, tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) { cin >> K[i]; }

	// 사람 왼쪽, 바구니 오른쪽 
	for (int i = 2; i < N; i++) {
		acc[i] = acc[i - 1] + K[i];
	} 
	if (maxi < acc[N-1] * 2) { maxi = acc[N - 1] * 2; }
	if (maxi < (acc[N-1] - K[2])

	// 사람 오른쪽, 바구니 왼쪽
	for (int i = N-3; i >= 0; i--) {
		acc[i] = acc[i - 1] + K[i];
	}
	if (maxi < acc[2] * 2) { maxi = acc[2] * 2; }

	cout << maxi << endl;

	return 0;
}