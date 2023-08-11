// 가랏! RC카!
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int num, Car = 0, speed = 0;
		cin >> num;

		for (int i = 0; i < num; i++) {
			int command, sec;
			cin >> command;

			if (command == 0) { // (유지)
				Car += speed;
			}

			else {
				cin >> sec;
				if (command == 1) { // (가속)
					for(int i = 0; i < sec; i++) speed++;
					Car += speed;
				}
				else { // command == 2 (감속)
					for (int i = 0; i < sec; i++) speed--;
					Car += speed;
				}
			}
		}

		int distance = Car;
		if (distance < 0) distance = 0;
		cout << "#" << tc + 1 << " " << distance << "\n";
	}

	return 0;
}