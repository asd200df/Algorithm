// 회의실 배정 (1931) Silver[1]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))
#define LL (long long)

using namespace std;

// Global
int N, cnt;
typedef struct {
	int start, end;
}node;
vector<node> vec;

// Function
void insol();
bool compare(node a, node b);

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N;

	int s, e, d;
	for (int i = 0; i < N; i++) { 
		cin >> s >> e;
		vec.push_back({ s, e });
	}

	sort(vec.begin(), vec.end(), compare);

	int prefix = -21e8;
	for (int i = 0; i < vec.size(); i++) {
		if (prefix > vec[i].start) { continue; }

		prefix = vec[i].end;
		cnt++;
	}

	cout << cnt << "\n";
}

// sort compare
bool compare(node a, node b) {
	if (a.end < b.end) { return true; }
	else if (a.end == b.end) { return a.start < b.start; }
	else { return false; }
}