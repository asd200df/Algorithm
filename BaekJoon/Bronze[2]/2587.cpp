// ´ëÇ¥°ª2 (2587) Bronze[2]
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int arr[6];

// Function
void insol();

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input && solution
void insol() {
	int average = 0;
	int middle_value = 0;

	for (int i = 0; i < 5; i++) { 
		cin >> arr[i]; 
		average += arr[i];
	}

	sort(arr, arr + 5);
	middle_value = arr[2];
	average /= 5;

	cout << average << "\n";
	cout << middle_value << "\n";
}