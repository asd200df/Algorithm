// 연월일 달력
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, day[13] = {0, 31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31 };
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int inp, year, month, date, tmp;
		string str;
		cin >> str;
		tmp = stoi(str);
		
		year = tmp / 10000;
		month = (tmp / 100) - year * 100;
		date = tmp % 100;

		if (month >= 1 && month <= 12 && date > 0 &&
			date <= day[month]) {
			cout << "#" << tc + 1 << " ";
			for (int i = 0; i < 4; i++) cout << str[i];
			cout << "/";
			for (int i = 4; i < 6; i++) cout << str[i];
			cout << "/";
			for (int i = 6; i < 8; i++) cout << str[i];
			cout << "\n";
		}
		else cout << "#" << tc + 1 << " -1\n";
	}

	return 0;
}