// 강의실 배정
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
int N;
typedef struct {
	int start, end;
}str;
vector<str> vec;

// Function
void input();
int solve();
bool compare(str s, str e);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	int result = solve();

	cout << result << "\n";

	/* debug
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i].start << " " << vec[i].end << "\n";
	}
	*/

	return 0;
}

// input
void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		vec.push_back({ tmp1, tmp2 });
	}
}

// compare
bool compare(str a, str b) {
	if (a.end < b.end) return true;
	else if (a.start == b.start) {
		if (abs(a.start - a.end) < abs(b.start - b.end)) return true;
		else return false;
	}
	else return false;
}

// solution
int solve() {
	int cnt = 0;
	str pre = { 0, 0 };

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++) {
		if (pre.start == vec[i].start) continue;
		if (pre.end > vec[i].start) continue;
		cnt++;
		pre = vec[i];
	}

	return cnt;
}