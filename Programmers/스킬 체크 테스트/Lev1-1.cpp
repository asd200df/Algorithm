// ��ų üũ �׽�Ʈ Lev1-1
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
string solution(string s) {
	string answer = "";

	// initialization
	int sz = s.size();
	int mid = sz / 2;

	// processor
	if (sz == 1 || sz == 2) { answer = s; } // exception
	else if ((sz % 2) == 1) { answer = s[mid]; } // Ȧ��
	else { // (sz % 2) == 0 // ¦�� 
		answer += s[mid - 1];
		answer += s[mid];
	}

	// return result !
	return answer;
}