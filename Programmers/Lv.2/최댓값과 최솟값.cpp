// ÃÖ´ñ°ª°ú ÃÖ¼Ú°ª
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// solve
string solution(string s) {
	string answer = "";

	// parsing
	int pre = 0;
	string now = "";
	vector<int> vec;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			vec.push_back(stoi(now));
			now = "";
		}
		else { now += s[i]; }
	}
	vec.push_back(stoi(now));

	/* debug
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	} */

	// sort
	sort(vec.begin(), vec.end());

	// update 
	answer = to_string(vec[0]) + " " + to_string(vec[vec.size() - 1]);

	// return result !
	return answer;
}
