// ¾ËÆÄºª Ã£±â (10809) Bronze[2]
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
string inp;
int arr[27];

// Function
void insol();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> inp;

	for (int i = 0; i < 26; i++) { arr[i] = -1; }

	int target;
	for (int i = 0; i < inp.size(); i++) {
		target = inp[i] - 'a';
		if (arr[target] == -1) { arr[target] = i; }
	}
	
	for (int i = 0; i < 26; i++) { cout << arr[i] << " "; }
	cout << "\n";
}