// ¼ýÀÚ Â¦²á
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// solve
string solution(string X, string Y) {
	string answer = "";

	// sort
	sort(X.begin(), X.end(), greater<int>());
	sort(Y.begin(), Y.end(), greater<int>());

	// Searching
	int start = 0;
	for (int i = 0; i < X.size(); i++) {

		for (int j = start; j < Y.size(); j++) {
			int ix = X[i] - '0';
			int iy = Y[j] - '0';

			if (ix > iy) { break; }
			else if (ix < iy) { start++; }
			else { // ix == iy
				start++;
				answer += to_string(ix);
				break;
			}
		}

		if (start == Y.size()) { break; }
	}

	// Exception
	if (answer.size() == 0) { answer = to_string(-1); }
	else if (answer[0] == '0') { answer = to_string(0); }

	// debug
	// cout << answer << "\n";

	// return result !    
	return answer;
}