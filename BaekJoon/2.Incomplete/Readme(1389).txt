// 케빈 베이컨의 6단계 법칙 (1389) Silver[1]



#0 Find rule
1 >> 0 2 1 1 2 = 6 
2 >> 2 0 1 2 3 = 8
3 >> 1 1 0 1 2 = 5
4 >> 1 2 1 0 1 = 5
5 >> 2 3 2 1 0 = 8
연결된 서로는 수가 같음 


#1 (틀렸습니다.)
1) input()
	// N <= 100, M <= 5,000
2) solve()
	// for(완탐)하는데, 
	// BFS()로 현재 자기 자신부터 바로 다음 숫자만 탐색
3) BFS()
	// 탐색 
4) solve()
	// 돌아와서 탐색 결과를 자기 자신이랑 다음 숫자에 
	// 알맞게 채워 넣음  
	

# 반례
5 5
6 8
6 9
9 10
9 8
8 7

똑같이 3 나와야 함 


1 >> 0 1 1 2 4
2 >> 1 0 1 1 3 
3 >> 1 1 0 1 3
4 >> 2 1 1 0 4
2












// 케빈 베이컨의 6단계 법칙 (1389) Silver[1]
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
int N, M; // N <= 100, M <= 5,000
int minimum = 21e8;
int arr[105]; // ret
int visit[105][105];
vector<vector<int>> vec(105);

// Function
void input();
void solve();
int BFS(int ins, int target);

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
		vec[v2].push_back(v1); // 양방향 연결 
	}
}

// solution
void solve() {
	int result = 0;

	// BFS func call
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			int bfs_ret;

			if (i == j) { continue; }
			if (visit[i][j] == 1) { continue; }

			visit[i][j] = 1;
			visit[j][i] = 1;

			bfs_ret = BFS(i, j);

			arr[i] += bfs_ret;
			arr[j] += bfs_ret;

			if (j == N) { // minimum value search
				minimum = min(minimum, arr[i]);
			}

			int debug = 0;
		}
	}

	// Exception
	minimum = min(minimum, arr[N]);

	// minimum num search
	for (int i = 1; i <= N; i++) {
		if (arr[i] == minimum) {
			result = i;
			break;
		}
	}

	/* debug
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		} cout << "\n";
	} */

	// print result
	cout << result << "\n";
}

// Breadth-First Search
int BFS(int ins, int target) {
	int used[105];
	typedef struct { int n, c; }node;
	queue<node> que;
	
	que.push({ ins, 0 });
	used[ins] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < vec[now.n].size(); i++) {
			int nn = vec[now.n][i];
			int nc = now.c + 1;

			if (used[nn] == 1) { continue; }
			if (nn == target) { return nc; }

			used[nn] = 1;

			que.push({ nn, nc });
		}
	}

	return -1;
}





