// ATM (11399) Silver[4]
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

#define fastIO (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));

using namespace std;

// Global
int N;
int people[1001];

// Function
void insol();

// Main
int main(int argc, char** argv) {
	fastIO;

	insol();

	return 0;
}

// input && solution
void insol() {
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> people[i]; }

	sort(people, people + N);

	int cumulative[1002] = { 0 };
	cumulative[0] = people[0];

	for (int i = 1; i < N; i++) {
		cumulative[i] = cumulative[i - 1] + people[i];
	}

	int sum = 0;
	for (int i = 0; i < N; i++) { sum += cumulative[i]; }

	cout << sum << "\n";

}