// Â¡°Ë´Ù¸® 
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
int N;
int bridge[3001];
vector<int> vec;

// Function
void insol();
void BS(int left, int right, int target);

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insol();

	cout << vec.size() << "\n";

	return 0;
}

// input & solution
void insol() {
	int target;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> bridge[i];
		target = bridge[i];

		if (i == 0 || vec.back() < target) { vec.push_back(target); }
		else { BS(0, vec.size() - 1, target); }
	}

}

// Binary Search
void BS(int left, int right, int target) {
	int idx;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (target == vec[mid]) { return; } // Ignore duplicate number
		else if (target < vec[mid]) { 
			right = mid - 1; 
			idx = mid;
		}
		else if (target > vec[mid]) { left = mid + 1; }
	}

	vec[idx] = target;
}