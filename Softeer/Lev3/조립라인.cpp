// 조립라인
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
int N; // <= 10^3
typedef struct {
	int dmv, mv;
}node;
node Ainp[1001], Binp[1001];
vector<int> Aline, Bline;

// Funtion
void input();
void solve();
void WS(int idx);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N;

	int a, b, amvb, bmva;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> amvb >> bmva;
		Ainp[i] = { a, amvb };
		Binp[i] = { b, bmva };
	}
	cin >> a >> b;
	Ainp[N - 1] = { a, 0 };
	Binp[N - 1] = { b, 0 };

	/* debug (input test)
	for(int i = 0; i < N; i++){
		cout << "A.dmv : " << Ainp[i].dmv << " A.mv : " << Ainp[i].mv << "\n";
		cout << "B.dmv : " << Binp[i].dmv << " B.mv : " << Binp[i].mv << "\n";
	} */

}

// solution
void solve() {
	int result = 0;

	// 초기값 설정
	Aline.push_back(Ainp[0].dmv);
	Bline.push_back(Binp[0].dmv);

	// Searching
	for (int now = 1; now < N; now++) {
		WS(now);
	}

	// update minimum
	result = min(Aline[N - 1], Bline[N - 1]);

	// Print Result !
	cout << result << "\n";
}

// Work Space
void WS(int idx) {
	int Aminimum = 21e8;
	int Bminimum = 21e8;

	// 더 해야 할 숫자들
	int Anow = Ainp[idx].dmv;
	int Bnow = Binp[idx].dmv;
	int AtoB = Ainp[idx - 1].mv;
	int BtoA = Binp[idx - 1].mv;

	// compare
	int value1 = Aline[idx - 1] + Anow; // A -> A
	int value2 = Bline[idx - 1] + BtoA + Anow; // B -> A 
	Aminimum = min(value1, value2);

	value1 = Bline[idx - 1] + Bnow; // B -> B
	value2 = Aline[idx - 1] + AtoB + Bnow; // A -> B
	Bminimum = min(value1, value2);

	// update
	Aline.push_back(Aminimum);
	Bline.push_back(Bminimum);
}