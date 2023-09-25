// ´õ ¸Ê°Ô 
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

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<long long, vector<long long>, greater<long long>> pq;

	for (int i = 0; i < scoville.size(); i++) {
		long long now = scoville[i];
		pq.push(now);
	}

	int cnt = 0;
	while (true) {
		long long n1, n2, sum;
		n1 = pq.top();
		pq.pop();

		if (pq.empty()) {
			if (n1 < K) {
				cnt = -1;
				break;
			}
		}

		n2 = pq.top();
		pq.pop();

		if (n1 >= K) { break; }
		cnt++;

		sum = n1 + (n2 * 2);

		pq.push(sum);
	}

	/* debug
	while(!pq.empty()){
		cout << pq.top() << "\n";
		pq.pop();
	} */

	answer = cnt;

	return answer;
}