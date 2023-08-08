// µ¦ 2 (28279) Silver[4]
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

using namespace std;

// Global
int N;

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

// input && solution
void insol() {
	cin >> N;

	deque<int> dq;
	int order, inp;
	while (N--) {
		cin >> order;

		switch (order) {
		case 1:
			cin >> inp;
			dq.push_front(inp);
			break;
		case 2:
			cin >> inp;
			dq.push_back(inp);
			break;
		case 3:
			if (dq.empty()) { cout << "-1\n"; }
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			break;
		case 4:
			if (dq.empty()) { cout << "-1\n"; }
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			break;
		case 5:
			cout << dq.size() << "\n";
			break;
		case 6:
			cout << dq.empty() << "\n";
			break;
		case 7:
			if (dq.empty()) { cout << "-1\n"; }
			else { cout << dq.front() << "\n"; }
			break;
		case 8:
			if (dq.empty()) { cout << "-1\n"; }
			else { cout << dq.back() << "\n"; }
			break;
		default:
			cout << "error\n";
			break;
		}
	}

}