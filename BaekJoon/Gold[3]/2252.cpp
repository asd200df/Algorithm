// �� ����� (2252) Gold[3]
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
int N, M; // N <= 32,000 // M <= 100,000
vector<vector<int>> vec(100005);
int degree[32005];

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
	cin >> N >> M;
	
	int v1 = 0;
	int v2 = 0;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		vec[v1].push_back(v2); // ���� inp
		degree[v2]++; // ���� ���� ++
	}
}

// solution
void solve() {
	queue<int> que;
	int result[32005];

	// ���� ������ 0�� ģ�� que�� �ֱ�
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			que.push(i);
		}
	}

	// ��� N Ž���ϱ�
	for (int i = 1; i <= N; i++) { 
		int now = que.front();
		que.pop();
		result[i] = now;

		for (int k = 0; k < vec[now].size(); k++) {
			int next = vec[now][k];

			// ����� ���� ����
			degree[next]--;

			// ���� �����ϴϱ� ���� ������ ���� ? �׷� que.push !
			if (degree[next] == 0) { que.push(next); }
		}

	}

	// print result
	for (int i = 1; i <= N; i++) {
		cout << result[i] << " ";
	} cout << "\n";
}