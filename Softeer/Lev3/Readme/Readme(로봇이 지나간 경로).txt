// 로봇이 지나간 경로 [HSAT 1회 - 1]


# 1 (구현 실패)
0. 자료구조 : vector, struct
1. input()
2. solve()
	for(vector.size()) { DFS() }
3. DFS(매개변수로 명령어 = string으로)
	※ used 사용하기, first 방향 저장하기
	※ A 한 번에 2칸 이동하는 거 인지 !
※ 방향 선택할 때 0, 1, 2, 3 % 4 로 해서 4방향 선택해서 넣겠끔 해야 돼 
	(이 전 위치를 기억하고 있어야 돼)
4. 결과 출력 ! (출력할 때 좌표 각각 +1 씩 해주어야 함)

---

# 2
0. 자료구조 : vector, struct
1. input()
2. solve()
	첫 방향 저장 
	DFS()
3. DFS(매개변수로 명령어 = string으로, 카운트, 이전 방향 저장 등)
	3방향 (왼 직진 오른쪽)
	갈 수 있는지 확인하는 함수
	※ used 사용하기 (항상 갔다 온 곳은 다시 0으로 바꿔주기)
	※ A 한 번에 2칸 이동하는 거 인지 !
	※ 방향 선택할 때 1, 2, 3 % 4 로 해서 3방향 선택해서 넣겠끔 해야 돼 

4. 결과 출력 ! (출력할 때 좌표 각각 +1 씩 해주어야 함)




#3 
// DFS() 와 방향 배열로 풀어보기 

※ 
상 우 하 좌
0  1  2  3

1 or 3 
1우 3좌 




#4 
0) 문제 이해
	// H행 W열
	// L 왼쪽을 본다, R 오른쪽을 본다, A 앞으로 2칸 전진한다
	// 같은 칸 두 번 방문하지 않는다
	// 처음 로봇이 어떤 방향을 보고 있었는지
	// 이후 로봇에 어떤 명령어를 어떤 순서로 입력해야하는지
	// 5 <= H, W <= 25, 2가지 방법 중 하나가 정답으로 출력 == 정답
1) input()
	// 시작점 찾아버려 (3면이 '.'이면 시작점 중 하나겠지)
2) solve()
	// dir[2][4] 방향이랑 dirMark[4] 랑 통일 시켜 놓음
	// find direction()로 갈 수 있는 방향 찾음
	// 이제 Navigate() 만들어야지 
	// Navigate(시작점, 방향) call !
3) Navigate (시작점, 방향)
	들어온 곳 map 바꿔주든 used 처리하든 !
	직진 할 수 있게 방향 바꿔주고 일단 !
	while(방향 바꿀꺼){
		while(직진할 것){
			여기서 dir 써서 방향 정해 
			(두 번 씩 갈 수 있게, 모르겠으면 2번써)
			다시 used나 map change 하면 되겠지 

			이제 다시 방향 찾아 일치하면 계속 직진
			다르면 빠져나와
		}
		if(만약 길이 아예 끝이면) break; 해야지
		
		dirMak = ^ < v > 와
		diry = -1 0 1 0
		dirx = 0 -1 0 1 기준으로 했을 때
		// 1씩 증가 좌회전
		// 1씩 감소면 우회전인데
		if(이전 방향 + 지금 방향) % 4 로 하면
		나머지가 1 이면 1씩 증가한 거랑 같은 의미고
		나머지가 3 이면 1씩 감소한 거랑 같은 의미야
		즉, %4 == 1 == 1증가 == 좌회전
		    %4 == 3 == 1 감소 == 우회전 인거지
		이전 방향, 지금 방향 갱신해야 돼 계속 	
	}
4) 이런식으로 결과 출력 !



@@@ 핵심은 이거야 @@@
앞으로 가야할 방향이 new dir 라고 하고 지금 방향이 pre dir 라고 했을 때
(pre dir + 1) % 4 이 new dir 랑 같은지
(pre dir + 3) % 4 이 new dir 랑 같은지 보는거야
+1 했을 때 같으면 우회전, +3 했을 때 같으면 좌회전인거야 
물론 이건, dir[2][4] = { 여기다 순서를 어떻게 하냐에 따라 다르긴 한데 }
상 우 하 좌 기준으로는 이렇게야 


----- 0 -----

[다른 사람 코드]

#include<iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int x;
    int y;
};
int mini = 21e8;
char map[27][27];
vector<Node> location;
int total;
int N, M;
int mov[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool visited[27][27];
char command[5] = { "^>v<" };
char startArrow;
Node start;
string ans;
bool check(int x, int y) {
    if (x <= 0 || x > N || y <= 0 || y > M) return 0;
    if (map[x][y] == '.') return 0;
    if (visited[x][y] == 1) return 0;

    return 1;
}
bool go(int x, int y,int arrow) {
    for (int a = 1; a <= 2; ++a) {
        int nx = x + mov[arrow][0] * a;
        int ny = y + mov[arrow][1] * a;
        if (!check(nx, ny))
            return 0;
    }
    return 1;
}

void paint(int x, int y, int arrow, int color) {
    for (int a = 1; a <= 2; ++a) {
        int nx = x + mov[arrow][0] * a;
        int ny = y + mov[arrow][1] * a;
        visited[nx][ny] = color;
    }
}
void dfs(int x, int y, int arrow, string path, int cnt) {
    if (path.length() >= mini)
        return;
    if (total == cnt) {
        mini = path.length();
        ans = path;
        return;
    }

    if (go(x, y, arrow)) {
        paint(x, y, arrow,1);
        dfs(x + mov[arrow][0] * 2, y + mov[arrow][1] * 2, arrow, path + "A", cnt + 2);
        paint(x, y, arrow, 0);
    }
    for (int a = 1; a <= 3; a += 2) {
        int nArrow = (arrow + a) % 4;
        if (go(x, y, nArrow)) {
            paint(x, y, nArrow, 1);
            string addWord;
            if (a == 1)
                addWord = "RA";
            else
                addWord = "LA";

            dfs(x + mov[nArrow][0] * 2, y + mov[nArrow][1] * 2, nArrow, path + addWord, cnt + 2);
            paint(x, y, nArrow, 0);
        }
    }
}
void solve() {
    for (int a = 0; a < location.size(); ++a) {
        Node now = location[a];
        visited[now.x][now.y] = 1;
        for (int b = 0; b < 4; ++b) {
            int before = mini;
            dfs(now.x, now.y,b,"",1);
            int after = mini;
            if (before != after) {
                startArrow = command[b];
                start = now;
            }
        }
        visited[now.x][now.y] = 0;
    }
    cout << start.x << " " << start.y << "\n" << startArrow << "\n" << ans;
}
void input() {
    cin >> N >> M;
    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= M; ++b) {
            cin >> map[a][b];
            if (map[a][b] == '#') {
                ++total;
                location.push_back({ a,b });
            }
        }
    }
}
int main(int argc, char** argv)
{

    input();
    solve();
	return 0;
}







