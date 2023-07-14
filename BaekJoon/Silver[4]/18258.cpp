// ť 2 (18258) Silver[4]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

#define FastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

using namespace std;

// Global
int N;
unordered_map<string, int> um;

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
	um["push"] = 1;
	um["pop"] = 2;
	um["size"] = 3;
	um["empty"] = 4;
	um["front"] = 5;
	um["back"] = 6;

	cin >> N;

	string order;
	int num = 0;
	queue<int> que;
	while (N--) {
		cin >> order;

		switch (um[order]){
		case 1: // push
			cin >> num;
			que.push(num);
			break;
		case 2: // pop
			if (que.empty()) { cout << "-1\n"; break; }
			cout << que.front() << "\n";
			que.pop();
			break;
		case 3: // size
			cout << que.size() << "\n";
			break;
		case 4: // empty
			cout << que.empty() << "\n";
			break;
		case 5: // fornt
			if (que.empty()) { cout << "-1\n"; break; }
			cout << que.front() << "\n";
			break;
		case 6: // back
			if (que.empty()) { cout << "-1\n"; break; }
			cout << que.back() << "\n";
			break;
		default:
			cout << "error\n";
			break;
		}

	}

}