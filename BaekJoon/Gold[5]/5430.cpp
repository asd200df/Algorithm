// AC (5430) Gold[5]
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
int T;

// Function
void insol();

// Main
int main(int argc, char** argv) {
	FastIO;

	cin >> T;
	for (int tc = 0; tc < T; tc++) { insol(); }

	return 0;
}

// input && solution
void insol() {
	bool flag = true;
	string order, parshing, result;
	int len = 0;
	deque<int> dq;

	// input
	cin >> order >> len >> parshing;

	// deque initialization
	string temp = "";
	for (int i = 1; i < parshing.size(); i++) {

		if (parshing[i] != ',' && parshing[i] != ']') {
			temp += parshing[i];
		}
		else {
			if (temp == "") { break; }
			dq.push_back(stoi(temp));
			temp = "";
		}

	}


	// solve
	bool reverse = false;
	for (int i = 0; i < order.size(); i++) {
		if(dq.empty() && order[i] == 'D') { 
			flag = false;
			break;
		}

		if (order[i] == 'R') {
			if (reverse == false) { reverse = true; }
			else { reverse = false; }
			continue;
		}

		if (order[i] == 'D') {
			if (reverse == false) { // 정방향
				dq.pop_front();
			}
			else { // reverse == true // 역방향
				dq.pop_back();
			}
		}
	}


	// last save
	int temp_flag = 0;
	while (!dq.empty()) {
		if (temp_flag == 1) { result += ','; }
	
		if (reverse == false) {
			result += to_string(dq.front());
			dq.pop_front();
		}
		else {
			result += to_string(dq.back());
			dq.pop_back();
		}

		temp_flag = 1;
	}


	// print result 
	if (flag) { cout << "[" << result << "]\n"; }
	else { cout << "error\n"; }
}