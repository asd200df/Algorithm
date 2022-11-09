// ½Ã°£ °³³ä
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

// global
string str1, str2;
int T1[8], T2[8], H1, M1, S1, H2, M2, S2;
int Hour, Min, Sec;

void parsing(string s1, string s2) { // parsing func 
	for (int i = 0; i < 8; i++) {
		if (s1[i] == ':' && s2[i] == ':') continue;
		T1[i] = s1[i] - '0';
		T2[i] = s2[i] - '0';
	}
	H1 = (T1[0] * 10) + T1[1];
	M1 = (T1[3] * 10) + T1[4];
	S1 = (T1[6] * 10) + T1[7];

	H2 = (T2[0] * 10) + T2[1];
	M2 = (T2[3] * 10) + T2[4];
	S2 = (T2[6] * 10) + T2[7];
}

void count() { // count func
	int cnt = 0;
	while (1) {
		cnt++; // count
		S1++; // 1sec
		if (S1 == 60) {
			S1 = 0;
			M1++;
		}
		if (M1 == 60) {
			M1 = 0;
			H1++;
		}
		if (H1 == 24) {
			H1 = 0;
		}

		if (H1 == H2 && M1 == M2 && S1 == S2) { break; }
	}
	int c = 0; // trace
	Hour = cnt / 10000;
	cnt %= 10000;
	Min = cnt / 100;
	Sec = cnt % 100;
}

void init() { // initialization func
	memset(T1, 0, sizeof(T1));
	memset(T2, 0, sizeof(T2));
	H1 = 0; 
	M1 = 0; 
	S1 = 0;
	H2 = 0;
	M2 = 0;
	S2 = 0;
	Hour = 0;
	Min = 0;
	Sec = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init(); // init func call
		cin >> str1 >> str2;
		
		parsing(str1, str2); // parsing func call
		int a = 0; // trace
		count();
		int b = 1; // trace
		cout << "#" << tc + 1 << " " << Hour << ":"
			<< Min << ":" << Sec << "\n";
	}

	return 0;
}