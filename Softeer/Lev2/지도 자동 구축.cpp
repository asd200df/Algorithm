// 지도 자동 구축
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

	/*  규칙 찾아보기

		1. 점의 수 증가
		4 >> 9 >> 25 >> 81

		2. 각각의 수의 제곱한 수가 점의 수
		2 3 5 9

		3. 2 3 5 9의 규칙
		이 전 숫자의 x2 -1 한 숫자
	*/

	int N, result, tmp = 2;
	cin >> N;

	// 규칙 적용
	for (int i = 0; i < N; i++) { tmp = (tmp * 2) - 1; }

	// 제곱하기 
	result = tmp * tmp;

	cout << result << "\n";

	return 0;
}