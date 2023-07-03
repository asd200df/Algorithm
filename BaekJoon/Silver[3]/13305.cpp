// ¡÷¿Øº“ (13305) Silver[3]
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
int N;
typedef struct {
	long long gasoline;
	long long cum_distance;
}node;
node nd[100001];

// Function
void input();
void solve();

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
	long long oil = 0;
	long long temp = 0;
	long long dis[100001] = { 0 };

	cin >> N;

	dis[0] = 0;
	for (int i = 1; i < N; i++) { 
		cin >> temp;
		dis[i] = dis[i - 1] + temp;
	}
	for (int i = 0; i < N; i++) {
		cin >> oil;
		nd[i] = { oil, dis[i] };
	}
}

// solution
void solve() {
	long long pay = 0;
	long long pre_oil = nd[0].gasoline;
	long long pre_dis = nd[0].cum_distance;
	long long post_oil = 0;
	long long post_dis = 0;

	for (int i = 1; i < N; i++) {
		post_oil = nd[i].gasoline;
		post_dis = nd[i].cum_distance;

		if (pre_oil > post_oil || i == (N - 1)) {
			pay += pre_oil * (post_dis - pre_dis);
			pre_dis = post_dis;
			pre_oil = post_oil;
		}

		// int debug2 = 0;
	}

	cout << pay << "\n";
}