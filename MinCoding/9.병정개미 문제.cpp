#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int ant[4][4], flag = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> ant[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j > 0 && ant[i][j] == 1 && ant[i][j - 1] == 1) flag = 1;
		}
	}

	if (flag == 1) cout << "������ ����" << endl;
	else cout << "������ ����" << endl;

	return 0;
}