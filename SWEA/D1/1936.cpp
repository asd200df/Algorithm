// 1대1 가위바위보
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	if (A == 1 || B == 1) {
		if (A == 3 || B == 3) {
			if (A < B) cout << "A\n";
			else if (A > B) cout << "B\n";
		}
		else {
			if (A > B) cout << "A\n";
			else if (A < B) cout << "B\n";
		}
	}
	else {
		if (A > B) cout << "A\n";
		else if (A < B) cout << "B\n";
	}

	return 0;
}