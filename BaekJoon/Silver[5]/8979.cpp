// 올림픽 (8979) Silver[5]
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
int N, K;
typedef struct { int country, G, S, B; }node;
vector<node> vec;

// Function
void input();
void solve();
bool compare(node A, node B);

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
	cin >> N >> K;

	int c, g, s, b = 0;
	for (int i = 0; i < N; i++) {
		cin >> c >> g >> s >> b;
		vec.push_back({ c, g, s, b });
	}
}

// solution
void solve() {

	sort(vec.begin(), vec.end(), compare);

	/* cout << "debug\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].country << " " << vec[i].G << " "
			<< vec[i].S << " " << vec[i].B << "\n";
	} */

	int rank = 1;
	int temp = 0;
	// int flag = 0;
	vec.push_back({ -1, -1, -1, -1 });
	for (int i = 0; i < vec.size() - 1; i++) {

		if (vec[i].country == K) { cout << rank << "\n"; }

		if (vec[i].G == vec[i + 1].G && vec[i].S == vec[i + 1].S &&
			vec[i].B == vec[i + 1].B) { // 공동 순위
			temp++;
		}
		else { 
			rank += temp;
			rank++;
			temp = 0;
		}
		
	}

}

// compare
bool compare(node A, node B) {

	if (A.G > B.G) { return true; }
	else if (A.G == B.G) {
		if (A.S > B.S) { return true; }
		else if (A.S == B.S) { return A.B > B.B; }
		else { return false; }
	}
	else { return false; }

}