// Çà·Ä µ¡¼À (2738) Bronze[5]
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
int N, M;
int arr[2][101][101];

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
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < N; k++) {
			for (int l = 0; l < M; l++) {
				cin >> arr[i][k][l];
			}
		}
	}
}

// solve
void solve() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[0][i][j] + arr[1][i][j] << " ";
		} cout << "\n";
	}

}