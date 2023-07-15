// �˰��� ���� - ���� �켱 Ž�� 1 (24479) Silver[2]
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
int N, M, R; // N <= 100,000
int cnt;
int used[100001];
int visit[100001];
vector<vector<int>> vec(100001);

// Function
void input();
void solve();
void DFS(int now);

// Main
int main(int argc, char** argv) {
	FastIO;

	input();
	solve();

	return 0;
}

// input
void input() {
	cin >> N >> M >> R;
	int start = 0;
	int end = 0;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		vec[start].push_back(end);
		vec[end].push_back(start); // ����� ����
	}
}

// solution
void solve() {

	// sort // �������� �湮�� ���� .. 
	for (int i = 0; i < N; i++) { sort(vec[i].begin(), vec[i].end()); }

	// call Funtion !
	DFS(R);

	// Print result ! 
	for (int i = 1; i <= N; i++) { cout << visit[i] << "\n"; }

}

// Depth-First Search
void DFS(int now) {
	// �湮 ó�� 
	visit[now] = ++cnt;
	used[now] = 1;
 
	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];

		if (used[next] == 1) { continue; }
		DFS(next);
	}
}