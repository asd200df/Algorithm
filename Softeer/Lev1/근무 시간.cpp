// 근무 시간
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

int main(int argc, char** argv) {
	int start_hour[5], start_min[5];
	int end_hour[5], end_min[5];
	int total = 0;

	for (int i = 0; i < 5; i++) {
		char tmp;
		cin >> start_hour[i] >> tmp >> start_min[i];
		cin >> end_hour[i] >> tmp >> end_min[i];
	}

	// 분 기준으로 변환하기 
	for (int i = 0; i < 5; i++) {
		int start_total = (start_hour[i] * 60) + start_min[i];
		int end_total = (end_hour[i] * 60) + end_min[i];

		total += end_total - start_total;
	}

	cout << total << "\n";

	return 0;
}