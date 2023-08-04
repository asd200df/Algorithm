// ������ (1766) Gold[2]
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
int degree[32005], result[32005];
vector<vector<int>> vec(32005);

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

	int v1, v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2;
		vec[v1].push_back(v2);
		degree[v2]++;
	}
}

// solution
void solve() {
	priority_queue<int, vector<int>, greater<int>> pq;

	// ó�� �������� 0�� ģ�� pq�� ���
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			pq.push(i);
		}
	}

	// ���� ���� ����
	for (int i = 1; i <= N; i++) {
		int now = pq.top();
		pq.pop();
		result[i] = now;

		for (int j = 0; j < vec[now].size(); j++) {
			int next = vec[now][j];
			
			// ���� �� ���� ����
			degree[next]--;

			// ���� �����ϴϱ� >> ���� ���� 0 �϶� 
			if (degree[next] == 0) {
				pq.push(next);
			}
		}
	}

	// ��� ��� !
	for (int i = 1; i <= N; i++) {
		cout << result[i] << " ";
	} cout << "\n";
}