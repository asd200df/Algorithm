// 세 용액 (2473) Gold[3]
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
int N; // 3 <= 5,000
bool flag = false;
long long liquid[5005];
long long temp[3];
long long result[3];
// -1,000,000,000 이상 1,000,000,000 이하이다

// Function
void input();
void solve();
long long BS(int ins);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> liquid[i]; }
}

// solution
void solve() {
	long long minimum = 3e9;

	sort(liquid, liquid + N);

	for (int i = 0; i < N - 2; i++) { // left right 있기에 -2
		long long tar = BS(i);
		if (flag) { break; }
		// int debug = 0;
		if (minimum > tar) {
			minimum = tar;
			result[0] = temp[0];
			result[1] = temp[1];
			result[2] = temp[2];
		}
	}

	sort(result, result + 3);
	cout << result[0] << " " << result[1] << " " << result[2];
}

// Binary Search
long long BS(int ins) {
	long long mini = 3e9;

	int fix = ins;
	int left = ins + 1;
	int right = N - 1;
	while (left < right) {
		long long sum = liquid[fix] + liquid[left] + liquid[right];

		if (sum == 0) {
			result[0] = liquid[fix];
			result[1] = liquid[left];
			result[2] = liquid[right];
			flag = true;
			return 0;
		}
		else if (sum < 0) {
			if (mini > abs(sum)) {
				mini = abs(sum);
				temp[0] = liquid[fix];
				temp[1] = liquid[left];
				temp[2] = liquid[right];
			}

			left++;
		}
		else { // sum > 0
			if (mini > abs(sum)) {
				mini = abs(sum);
				temp[0] = liquid[fix];
				temp[1] = liquid[left];
				temp[2] = liquid[right];
			}

			right--;
		}
	}

	return mini;
}