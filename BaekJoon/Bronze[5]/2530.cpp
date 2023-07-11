// ¿µ¼öÁõ (2530) Bronze[5]
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
long long total, N;

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

// input & solution
void insol() {
	cin >> total >> N;

	long long result = 0;
	int t1 = 0;
	int t2 = 0;
	for (int i = 0; i < N; i++) { 
		cin >> t1 >> t2;
		if (t2 != 0) { result += t1 * t2; } 
		else { result += t1; }
	}

	if (total == result) { cout << "Yes\n"; }
	else { cout << "No\n"; }
}
