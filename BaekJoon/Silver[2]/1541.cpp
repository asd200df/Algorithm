// 잃어버린 괄호 (1541) Silver[2]
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

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int arr[51];

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
	string inp;
	cin >> inp;

	int result = 0;

	// ※ 앞에 -가 나오면 그 뒤로 +는 -로 바꾸어도 되는거야
	// 55-(50+45) == 55-50-45 == -40 이니까 

	// parshing && calculator
	char ch;
	string st;
	int idx = 0;
	bool flag = false;
	for (int i = 0; i < inp.size(); i++) {
		ch = inp[i];

		if (ch == '+' || ch == '-' || i == inp.size() - 1) {
			
			if (i == inp.size() - 1) { st += ch; }


			if (flag) { // 앞에 - 가 있는 경우
				result -= stoi(st);
			}
			else { // 앞에 - 가 없는 경우
				result += stoi(st);
			}

			st = "";
		}
		else { st += ch; }
		
		if (ch == '-') { flag = true; }
	}

	int debug = 0;

	cout << result << "\n";
}