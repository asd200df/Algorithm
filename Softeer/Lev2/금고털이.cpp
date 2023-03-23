// ±›∞Ì≈–¿Ã
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int limit, N, gold_sum;
typedef struct {
	int weight;
	int gold;
}str;
vector<str> vec;

// Function
void input();
int solve();
bool compare(str a, str b);

// MAIN
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	sort(vec.begin(), vec.end(), compare);

	int result = solve();

	cout << result << "\n";

	return 0;
}

// input
void input() {
	cin >> limit >> N;

	for (int i = 0; i < N; i++) {
		int tmp_limit, tmp_gold;
		cin >> tmp_limit >> tmp_gold;
		vec.push_back({ tmp_limit, tmp_gold });
	}
}

// solution
int solve() {
	int cnt = 0, chance = 1, sum = 0, flag = 0;

	while (1) {
		int next_w = vec[cnt].weight;
		int next_g = vec[cnt].gold;

		if (chance == 0) break;

		if (sum + next_w <= limit) {
			sum += next_w;
			gold_sum += (next_w * next_g);
			flag = 1;
		}
		else if (sum + next_w > limit) {
			if (flag == 0) break;
			int dif = limit - sum;
			gold_sum += (dif * next_g);
			chance = 0;
		}

		cnt++;
	}

	return gold_sum; // temp
}

// sort
bool compare(str a, str b) {
	if (a.gold > b.gold) return true;
	if (a.gold < b.gold) return false;
}