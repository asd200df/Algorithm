// ¿Àºì ½Ã°è (2525) Bronze[3]
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
int H, M, V;

// Function
void insol();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insol();

	return 0;
}

// input & solution
void insol() {
	cin >> H >> M >> V;

	int minute = (M + (60 * H)) + V;
	
	H = minute / 60;
	M = minute % 60;

	if (H > 23) { H = H % 24; }

	cout << H << " " << M << "\n";
}
