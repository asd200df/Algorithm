// 가장 먼 노드
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Global
int dis[50001];
int used[20001];
int maxi = -21e8;
vector<vector<int>> vec(20001);
typedef struct {
	int gps;
	int wv; // weight value (가중치)
}node;

// function
void BFS(int start);

// solve
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	// input
	int v[2] = { 0 };
	for (int i = 0; i < edge.size(); i++) {
		for (int j = 0; j < 2; j++) {
			v[j] = edge[i][j];
		}

		vec[v[0]].push_back(v[1]);
		vec[v[1]].push_back(v[0]); // 양방향 연결
	}

	// debug
	// for(int i = 1; i <= n; i++){
	//     for(int j = 0; j < vec[i].size(); j++){
	//         cout << vec[i][j] << " ";
	//     } cout << "\n";
	// }

	// function call
	BFS(1);

	// result update
	answer = dis[maxi];

	// return result 
	return answer;
}

// Breadth-First Search
void BFS(int start) {
	queue<node> que;
	que.push({ start, 0 });
	used[start] = 1;

	while (!que.empty()) {
		node now = que.front();
		que.pop();

		for (int i = 0; i < vec[now.gps].size(); i++) {
			int next = vec[now.gps][i];
			int nwv = now.wv + 1;

			if (used[next] == 1) { continue; }

			used[next] = 1;
			dis[nwv]++;

			maxi = max(maxi, nwv);

			que.push({ next, nwv });
		}
	}

}