// 인간-컴퓨터 상호작용 (16139) Silver[1]
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
char ch[200002];
int Q;
int used[27][200001] = { 0 };

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
	cin >> ch >> Q;

	string temp = ch;
	int dif = 'a';
	char target = ch[0];

	used[target-dif][0] = 1;

	for (int i = 1; i < temp.size(); i++) { // cumulative cum
		target = ch[i] - dif;

		for (int j = 0; j < 27; j++) { // copy
			used[j][i] = used[j][i - 1];
		}

		used[target][i]++;
	}

	int debug = 0;

	int L = 0;
	int R = 0;
	int result = 0;
	for (int i = 0; i < Q; i++) { // result cout !
		cin >> target >> L >> R;
		
		target -= dif;
		// L++;
		// R++;

		if (L == 0) {
			result = used[target][R];
		}
		else {
			if (used[target][R] - used[target][L - 1] >= 0) {
				result = used[target][R] - used[target][L - 1];
			}
		}

		cout << result << "\n";
	}

}
