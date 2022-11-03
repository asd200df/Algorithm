7701. 염라대왕의 이름 정렬

설계

방법[1] 
1 input (testcase, N, 이름들 ...) 받기
2 이름들 vector<string> 에 저장
3 sort 할건데 compare 함수 만들어서 
	sort( , , compare) 구현
4 compare 함수에선 길이가 짧을 수록 우선 순위 높고 같을 땐
	사전 순으로 우선 순위 높게 정의 해주고
5 vector<string> 으로 받은 이름들 sort 시켜서
6 output에 맞게 출력해주면 끝


방법[2]
0 unordered_map 사용하기 


[반례]
abc
b
zc

[input]
2  test case
5  N
my
name
is
ho
seok

12
s
a
m
s
u
n
g
j
j
a
n
g


[output]
#1
ho
is
my
name
seok

#2
a
g
j
m
n
s
u


[1]
// 염라대왕의 이름 정렬
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
vector<string> vec;

bool compare(string s, string t) {
	if (s.length() < t.length()) return 1;
	else if (s.length() > t.length()) return 0;
	else if (s.length() == t.length()) {
		return s < t;
	}
}

void init() { // initialization function
	N = 0;
	vec.clear();
}

int main() { // main
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		cin >> N;

		for (int i = 0; i < N; i++) {
			string tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}

		sort(vec.begin(), vec.end(), compare);

		cout << "#" << tc + 1 << endl;
		for (int i = 0; i < N; i++) { // sort test
			if (i != 0 && vec[i - 1] == vec[i]) continue;
			cout << vec[i] << endl;
		}
	}

	return 0;
}



[2]
// 염라대왕의 이름 정렬
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
unordered_map<string, int> um;

bool compare(pair<string, int> s, pair<string, int> t) {
	if (s.first.length() < t.first.length()) return 1;
	else if (s.first.length() > t.first.length()) return 0;
	else if (s.first.length() == t.first.length()) {
		return s.first < t.first;
	}
}

void init() { // initialization function
	N = 0;
	um.clear();
}

int main(){ // main
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		cin >> N;

		for (int i = 0; i < N; i++) {
			string tmp;
			cin >> tmp;
			um[tmp]++;
		}
		vector<pair<string, int>> vec(um.begin(), um.end());
		sort(vec.begin(), vec.end(), compare);

		cout << "#" << tc << "\n";
		for (int i = 0; i < vec.size(); i++) { 
			cout << vec[i].first << "\n";
		}
	}

	return 0;
}








