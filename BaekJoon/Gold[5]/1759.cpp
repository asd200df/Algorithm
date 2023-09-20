// 암호 만들기 (1759) Gold[5]
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
int L, C; // <= 15
char mo[5] = { 'a', 'e', 'i', 'o', 'u' };
vector<char> vec;
vector<string> result;
unordered_map<char, bool> used;
unordered_map<char, bool> mo_used;
char pw[20];

// Function
void input();
void solve();
void DFS(int cnt);
bool valid();

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
	cin >> L >> C;

	// initialization
	for (int i = 0; i < 5; i++) { mo_used[mo[i]] = false; }
	 
	// inp
	char inp;
	for (int i = 0; i < C; i++) {
		cin >> inp;
		vec.push_back(inp);
		used[inp] = false;
	}
}

// solution
void solve() {

	// DFS func call
	DFS(0);

	// sort
	sort(result.begin(), result.end());

	// print result !
	if (result.empty()) { return; }
	else { for (int i = 0; i < result.size(); i++) { cout << result[i] << "\n"; } }
}

// Depth-First Search
void DFS(int cnt) {
	if (cnt == L) {
		if (!valid()) { return; }

		string candidate;
		for (int i = 0; i < L; i++) { candidate += pw[i]; }
		
		result.push_back(candidate);

		return;
	}

	for (int i = 0; i < vec.size(); i++) {
		char now = vec[i];
		
		// 1. 중복 제거
		if (used[now]) { continue; } 
		// 2. 다음이 더 작으면 제거
		if (cnt != 0 && pw[cnt - 1] > now) { continue; }

		if (now == 'a' || now == 'e' || now == 'i' || now == 'o' || now == 'u') {
			mo_used[now] = true;
		}

		used[now] = true;
		pw[cnt] = now;
		DFS(cnt + 1);
		used[now] = false;

		if (now == 'a' || now == 'e' || now == 'i' || now == 'o' || now == 'u') {
			mo_used[now] = false;
		}
	}
}

// valid check
bool valid() {
	int m_cnt = 0;
	int j_cnt = 0;

	// check
	for (int i = 0; i < L; i++) {
		char nm = pw[i];

		if (mo_used[nm]) { m_cnt++; }
		else { j_cnt++; }
	}

	// return
	if (m_cnt >= 1 && j_cnt >= 2) { return true; }
	else { return false; }
}