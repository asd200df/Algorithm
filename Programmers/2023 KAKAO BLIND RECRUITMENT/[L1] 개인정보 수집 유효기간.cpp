// 개인정보 수집 유효기간
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

// global
unordered_map<char, int> um;
vector<string> vec;
typedef struct { int ty, tm, td; } node;
node Today;

// function
// -

// solve
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	// convert
	vec.push_back("temp");
	for (int i = 0; i < privacies.size(); i++) { vec.push_back(privacies[i]); }
	for (int i = 0; i < terms.size(); i++) {
		char inp1;
		string inp2;
		int temp;

		inp1 = terms[i][0];
		for (int j = 1; j < terms[i].size(); j++) {
			inp2 += terms[i][j];
		} temp = stoi(inp2);

		um[inp1] = temp;
	}
	string yy, mm, dd;
	for (int i = 0; i <= 3; i++) {
		yy += today[i];
		if (i >= 2) { continue; }
		mm += today[i + 5];
		dd += today[i + 8];
	}
	Today.ty = stoi(yy);
	Today.tm = stoi(mm);
	Today.td = stoi(dd);

	// search  
	for (int i = 1; i < vec.size(); i++) {
		string year, month, date;
		char kind;

		// parsing
		for (int j = 0; j <= 3; j++) {
			year += vec[i][j]; // year
			if (j >= 2) { continue; }
			month += vec[i][j + 5]; // month
			date += vec[i][j + 8]; // date
		} kind = vec[i][11]; // kind

		// trans
		int y, m, d;
		y = stoi(year);
		m = stoi(month);
		d = stoi(date);

		m += um[kind];

		while (m > 12) {
			y++;
			m -= 12;
		}

		if (y < Today.ty) {
			answer.push_back(i);
			continue;
		}
		else if (y > Today.ty) { continue; }

		if (m < Today.tm) {
			answer.push_back(i);
			continue;
		}
		else if (m > Today.tm) { continue; }

		if (d <= Today.td) { answer.push_back(i); }

	}

	return answer;
}