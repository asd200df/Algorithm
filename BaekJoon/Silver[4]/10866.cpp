// µ¦ (10866) Silver[4]
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
int N;

// Function
void insol();

// Main
int main(int argc, char** argv) {
	FastIO;

	insol();

	return 0;
}

// input & solution
void insol() {
	cin >> N;

	string order;
	int num;
	deque<int> dq;
	for (int i = 0; i < N; i++) {
		cin >> order;

		if (order == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (order == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (order == "pop_front") {
			if (dq.empty()) { cout << "-1\n"; continue; }
			cout << dq.front() << "\n";
			dq.pop_front();
		}
		else if (order == "pop_back") {
			if (dq.empty()) { cout << "-1\n"; continue; }
			cout << dq.back() << "\n";
			dq.pop_back();
		}
		else if (order == "size") {
			cout << dq.size() << "\n";
		}
		else if (order == "empty") {
			cout << dq.empty() << "\n";
		}
		else if (order == "front") {
			if (dq.empty()) { cout << "-1\n"; continue; }
			cout << dq.front() << "\n";
		}
		else if (order == "back") {
			if (dq.empty()) { cout << "-1\n"; continue; }
			cout << dq.back() << "\n";
		}


	}

}