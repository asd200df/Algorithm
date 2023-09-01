// 양과 늑대
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

// global
int maxi = -21e8;
vector<int> Info;
vector<vector<int>> vec(20);
bool used[20][20][20]; // [다음노드][양][늑대]

// function
void DFS(int now, int sheep, int wolf);

// solve
int solution(vector<int> info, vector<vector<int>> edges) {
	int answer = 0;

	// convert
	Info = info;
	int v1, v2;
	for (int i = 0; i < edges.size(); i++) {
		v1 = edges[i][0];
		v2 = edges[i][1];
		vec[v1].push_back(v2);
		vec[v2].push_back(v1); // 양방향 연결 
	}

	/* debug
	for(int i = 0; i < Info.size(); i++){
		cout << i << " : ";
		for(int j = 0; j < vec[i].size(); j++){
			cout << vec[i][j] << ", ";
		}
		cout << "\n";
	} */

	// DFS func call
	used[0][1][0] = true;
	Info[0] = -1;
	DFS(0, 1, 0);

	// update result 
	answer = maxi;

	// return result !
	return answer;
}

// Depth-First Search
void DFS(int now, int sheep, int wolf) {
	if (now == 0) { // 지금이 Root 노드 일 때
		// cout << sheep << " " << wolf << "\n";
		maxi = max(maxi, sheep);
		// return;
	}

	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];
		int nxt = Info[next];

		if (nxt == 0) { // 다음이 양 일 때
			if (used[next][sheep + 1][wolf] == true) { continue; }
			used[next][sheep + 1][wolf] = true;
			Info[next] = -1;
			DFS(next, sheep + 1, wolf);
			Info[next] = 0;
			used[next][sheep + 1][wolf] = false;
		}
		else if (nxt == 1) { // 다음이 늑대 일 때
			if (sheep <= wolf + 1) { continue; }
			if (used[next][sheep][wolf + 1] == true) { continue; }
			used[next][sheep][wolf + 1] = true;
			Info[next] = -1;
			DFS(next, sheep, wolf + 1);
			Info[next] = 1;
			used[next][sheep][wolf + 1] = false;
		}
		else { // 다음이 비어 있을 때 
			if (used[next][sheep][wolf] == true) { continue; }
			used[next][sheep][wolf] = true;
			DFS(next, sheep, wolf);
			used[next][sheep][wolf] = false;
		}
	}
}