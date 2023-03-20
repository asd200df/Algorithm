// 우물 안 개구리 
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
int N, M;
int arr[100002];
vector<vector<int>> vec(100002);

// Function
void input();
int solve();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	int result = solve();

	cout << result << "\n";

	return 0;
}

// input
void input() {
	int tmp1 = 0, tmp2 = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> tmp1;
		arr[i] = tmp1;
		vec[i].push_back(tmp1); // 본인 무게 가장 앞에 넣어주기 
	}
	for (int i = 1; i <= M; i++) {
		cin >> tmp1 >> tmp2;
		vec[tmp1].push_back(arr[tmp2]); // 양방향 연결 
		vec[tmp2].push_back(arr[tmp1]);
	}
}

// solve
int solve() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int ego = vec[i][0];
		int max = -21e8;
		for (int j = 1; j < vec[i].size(); j++) {
			if (vec[i][j] > max) {
				max = vec[i][j];
			}
		}
		if (max == -21e8 || ego > max) cnt++;
	}

	return cnt;
}

/* debug
	for(int i = 1 ; i <= N; i++){
		for(int j = 0; j < vec[i].size(); j++){
			cout << vec[i][j] << " ";
		} cout << endl;
	}
	cout << endl;
*/