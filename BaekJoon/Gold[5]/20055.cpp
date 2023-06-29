// 컨베이어 벨트 위의 로봇 (20055) Gold[5]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;

// Global
int N, K, total;
typedef struct {
	int Durability;
	bool robot;
}node;
node rail[205];

// Function
void input();
void solve();
void rail_mv();
void robot_mv();
void robot_pud(int type);

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
	cin >> N >> K;

	int temp = 0;
	for (int i = 0; i < (N * 2); i++) { 
		cin >> temp;
		rail[i] = { temp, false };
	}
}

// solution
void solve() {
	int cnt = 0;

	while(true){
		cnt++;

		// 1) rail move !
		rail_mv();
		int debug1 = 0;

		// 2) robot down
		robot_pud(1);
		int debug2 = 0;

		// 3) robot move !
		robot_mv();
		int debug3 = 0;

		// 4) robot put up & down
		robot_pud(2);
		int debug4 = 0;

		// 5) end condition
		if (K <= total) { break; }
	}

	cout << cnt << "\n";
}

// rail move
void rail_mv() {
	int idx = (N * 2) - 1;
	int temp = rail[idx].Durability;
	int temp2 = rail[idx].robot;

	for (int i = idx; i >= 0; i--) {

		if(i == 0) { 
			rail[i].Durability = temp; 
			rail[i].robot = temp2;
		}
		else { 
			rail[i].Durability = rail[i - 1].Durability;
			rail[i].robot = rail[i - 1].robot;
		}

	}
}

// robot move
void robot_mv() {

	for (int i = N - 1; i >= 0; i--) {
		if (rail[i].robot == true) { continue; } 
		if (rail[i].Durability == 0) { continue; } 
		if (rail[i - 1].robot == false) { continue; } 

		rail[i - 1].robot = false;
		rail[i].robot = true;
		rail[i].Durability--;
	}
}

// robot put up & down
void robot_pud(int type) { // type == 1 (down), type == 2 (up & down)
	total = 0; // 여기서 내구도 체크 해줘야 돼

	if (type == 1) { rail[N - 1].robot = false; }
	else { // type == 2
		rail[N - 1].robot = false;
		if (rail[0].robot != true && rail[0].Durability != 0) {
			rail[0].robot = true;
			rail[0].Durability--;
		}

		for (int i = 0; i < (N * 2); i++) { if (rail[i].Durability == 0) { total++; } }
	}

}