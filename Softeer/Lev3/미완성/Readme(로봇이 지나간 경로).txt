로봇이 지나간 경로 [HSAT 1회 정기 코딩 인증평가 기출]


# 1
1. input()
2. solve()
	DFS()
3. DFS(매개변수로 명령어 = string으로)
	※ used 사용하기 

※ A 한 번에 2칸 이동하는 거 인지 !
※ 방향 선택할 때 0, 1, 2, 3 % 4 로 해서 4방향 선택해서 넣겠끔 해야 돼 
	(이 전 위치를 기억하고 있어야 돼)



```
// 로봇이 지나간 경로 [HSAT 1회 정기 코딩 인증평가 기출]
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
int H, W;
char map[27][27];
int used[27][27];
int dirY[] = { 0, 0, -2, 2 };
int dirX[] = { -2, 2, 0, 0 };
char direct[] = { '<', '>', '^', 'v' };
char pre = '';
typedef struct{
	int y, x;
} str;
vector<str> vec;

// Function
void input();
void solve();
void DFS();

// Main
int main(int argc, char** argv){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

// input
void input(){
	cin >> H >> W;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> map[i][j];
			if(map[i][j] == '#') { vec.push_back({i, j}); }
		}
	}
}

// solution
void solve(){

	for(int i = 0; i < vec.size(); i++){
		str now;
		now = vec[i];

		// 제 자리 used 처리 
		DFS(now, 0);

		for(int i = 0; i < 27; i++) { memset(used[i], 0, sizeof(used)); } 
	}

	// 마지막에 좌표 출력할 때 +1 씩 해줘야 함 

}

// Depth-First Search
void DFS(str now, int cnt){
	if(cnt == vec.size() - 1){

	}

	for(int i = 0; i < 4; i++){
		int ny = now.y + dirY[i];
		int nx = now.x + dirX[i];

		if(ny < 0 || ny >= H || nx < 0 || nx >= W){ continue; }
		if(map[ny][nx] == '.') { continue; }
		if(used[ny][nx] == 1) { continue; }

		used[ny][nx] = 1;

		DFS({ny, nx}, cnt + 1);

		used[ny][nx] = 0; // 다시 가는 길 열어줘야 돼 (어차피 for문은 돌기 때문에 다시 안가)
	}

}
```




