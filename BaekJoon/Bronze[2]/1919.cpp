// 애너그램 만들기 (1919) Bronze[2]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
string a, b;
int used1[129];
int used2[129];

// Function
void input();
void solve();

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
	cin >> a >> b;
}

// solve
void solve() {
	int cnt = 0;

	for (int i = 0; i < a.size(); i++) { used1[a[i]]++; }
	for (int i = 0; i < b.size(); i++) { used2[b[i]]++; }
	// int debug = 0;
	
	for (int i = 97; i < (97 + 26); i++) {
		cnt += abs(used1[i] - used2[i]);
	}

	cout << cnt << "\n";
}
