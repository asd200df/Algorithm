// 미생물 격리 
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// global
int N, M, K, sum;
// int map[101][101];
int cumulative[101][101], maxi[101][101], maxdir[101][101];
typedef struct {
	int y, x, num, dir;
}str;
vector<str> vec;

void join() { // join func 
	vector<str> vectmp;
	sum = 0;
	memset(cumulative, 0, sizeof(cumulative));
	memset(maxi, 0, sizeof(maxi));
	memset(maxdir, 0, sizeof(maxdir));

	for (int i = 0; i < vec.size(); i++) {
		// 1. cumulative sum 
		cumulative[vec[i].y][vec[i].x] += vec[i].num;
		// 2. max & 3. max direction
		if (maxi[vec[i].y][vec[i].x] < vec[i].num) {
			maxi[vec[i].y][vec[i].x] = vec[i].num; // max
			maxdir[vec[i].y][vec[i].x] = vec[i].dir; // dir
		}
	}

	// temp vector update ? 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cumulative[i][j] > 0) {
				vectmp.push_back({ i, j, cumulative[i][j], maxdir[i][j] });
				sum += cumulative[i][j];
			}
		}
	}
	// vector update
	vec = vectmp;
}

void redzone() { // red zone func
	for (int i = 0; i < vec.size(); i++) {
		// redzone
		if (vec[i].x == 0 || vec[i].x == N - 1 ||
			vec[i].y == 0 || vec[i].y == N - 1) {
			
			// 방향 전환
			if (vec[i].dir == 1) { vec[i].dir = 2; }
			else if (vec[i].dir == 2) { vec[i].dir = 1; }
			else if (vec[i].dir == 3) { vec[i].dir = 4; }
			else if (vec[i].dir == 4) { vec[i].dir = 3; }
			
			// 미생물 수 감소
			if (vec[i].num == 1) { // 1마리 남았을 경우
				vec[i].num = 0;
			}
			else{
				vec[i].num /= 2;
			}
		}

	}
}

void move() { // move func
	for (int i = 0; i < vec.size(); i++) {
		// 상 : 1
		if (vec[i].dir == 1) { vec[i].y--; }
		// 하 : 2
		else if (vec[i].dir == 2) { vec[i].y++; }
		// 좌 : 3
		else if (vec[i].dir == 3) { vec[i].x--; }
		// 우 : 4
		else if (vec[i].dir == 4) { vec[i].x++; }
	}
}

int solve() { // func control func >> solution
	// time == 0 (초기 상태)
	for (int time = 1; time <= M; time++) {
		move();
		redzone();
		join();
	}
	return sum;
}

void input() { // input func
	cin >> N >> M >> K; // 셀 수, 격리 시간, 군집 갯수
	for (int i = 0; i < K; i++) {
		int ty, tx, tnum, tdir;
		cin >> ty >> tx >> tnum >> tdir;
		vec.push_back({ ty, tx, tnum, tdir });
	}
}

void init() { // initialization func
	sum = 0;
	memset(cumulative, 0, sizeof(cumulative));
	memset(maxi, 0, sizeof(maxi));
	memset(maxdir, 0, sizeof(maxdir));
	vec.clear();
}

int main() { // main()
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		input();

		int result = solve();
		cout << "#" << tc + 1 << " " << result << "\n";
	}

	return 0;
}