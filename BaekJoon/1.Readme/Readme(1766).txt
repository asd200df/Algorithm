// 문제집 (1766) Gold[2]



#1 
위상정렬 하는데 우선순위 큐 써서 하면 될 것 같음 
// priority_queue<int, vector<int>, greater<int>) pq;
1) input()
	// vector[2차원] >> 노드 받을 꺼
	// Degree[1차원] >> 진입 차수 체크할 꺼
	// result[정답 받을 배열] + priority_queue 준비 !
2) solve()
	// 진입 차수 0인 것 pq(priority_queue)에 담기
	// for(N 전체 다 돌기) {
	// 	for(vector[now].size) {
	// 		위상정렬 진행 
	// 	}
	// }
3) Print result !











