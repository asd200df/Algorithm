// 나머지 (10430) Bronze[5]
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
int A, B, C;

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
	cin >> A >> B >> C;
}

// solution
void solve() {
	// 첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 
	// 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.

	cout << (A + B) % C << "\n" << ((A%C) + (B%C)) % C << "\n" <<
		(A*B) % C << "\n" << ((A%C) * (B%C)) % C << "\n";

}