// 소트인사이드 (1427) Silver[5]
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
string stN;
vector<char> vec;

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
	cin >> stN;

	for (int i = 0; i < stN.size(); i++) { 
		vec.push_back(stN[i]); 
	}

	sort(vec.begin(), vec.end());

	for (int i = vec.size() - 1; i >= 0; i--) { 
		cout << vec[i]; 
	} cout << "\n";
}
