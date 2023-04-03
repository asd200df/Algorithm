// 주행거리 비교하기 
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

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	if (A > B) cout << "A\n";
	else if (A < B) cout << "B\n";
	else cout << "same\n";

	return 0;
}