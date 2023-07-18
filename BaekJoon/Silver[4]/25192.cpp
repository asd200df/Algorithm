// ¿ŒªÁº∫ π‡¿∫ ∞ı∞ı¿Ã (25192) Silver[4]
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int N;

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

	int cnt = 0;
	set<string> table;
	string inp;

	for (int i = 0; i < N; i++) {
		cin >> inp;
		
		if (inp == "ENTER") { 
			cnt += table.size();
			table.clear();
			continue; 
		}
		else { table.insert(inp); }
	}

	cnt += table.size();

	cout << cnt << "\n";
}