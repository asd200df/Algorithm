// 도키도키 간식드리미 (12789) Silver[3]
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
void insolve();

// Main
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	insolve();

	return 0;
}

// input && solution
void insolve() {
	cin >> N; // <= 1000

	// inp
	int arr[1001];
	stack<int> line1, line2;
	for (int i = 0; i < N; i++) { cin >> arr[i]; }
	for (int i = N-1; i >= 0; i--) { line1.push(arr[i]); }


	// Search
	int target = 1; // 현재 번호표
	int now1, now2;
	int before1, before2;
	while (target <= N) {
		before1 = line1.size();
		before2	= line2.size();

		if (before1 != 0) { now1 = line1.top(); }

		if (before1 != 0 && now1 == target) {
			line1.pop();
			target++;
		}
		else { // (now1 != target) 
			if (line2.empty()) { 
				line2.push(now1);
				line1.pop();
			}
			else { // !line2.empty()
				now2 = line2.top();
				
				if (now2 == target) {
					line2.pop();
					target++;
				}
				else { // now2 != target
					if (!line1.empty()) {
						line2.push(now1);
						line1.pop();
					}
				}
			}
		}

		if (line1.empty() && line2.empty()) { break; }
		if (before1 == line1.size() && before2 == line2.size()) { break; }
	}


	// Print result
	if (line1.empty() && line2.empty()) { cout << "Nice\n"; }
	else { cout << "Sad\n"; }
}