// 최종 순위 (3665) Gold[1]



#1 
// 위상정렬하는데 예외처리가 중요한 것 같음
// 사이클이 형성 되었을 때 '?' 를 출력하는 것 등
// test case 가 있는 문제 == 초기화 잘 해주어야 함 
0) set
	// vector[1차원] >> N 받을 꺼 >> N이 1 2 3 .. 5 이 순서가 아니라서 
	// vector[2차원] >> 노드 받을 꺼
	// degree[1차원] >> 진입 차수 check
	// result[] 결과 담을 꺼
1) input()
	// N <= 500, M <= 25000
2) solve()
	// 처음 진입 차수 0인 것 queue 에 담기 혹시 없으면 '?' 출력 (싸이클 형성)
	// 위상정렬 진행
3) 결과 출력
	// result 와 처음 N 입력이 같으면 "IMPOSSIBLE" 출력 ? 
	// 아니면 결과(result) 출력 


※ 처음 들어오는 순위도 degree 에 체크 해줘야 돼 1순위가 2345 2순위가 345 ... 이렇게
	그 다음 들어오는 간선(순위 변동된 친구들) 다시 degree 바꿔줘야 돼 


※ 조건 : "IMPOSSIBLE"을 출력
위상 정렬을 적용할 수 없는 경우는 그래프에 사이클이 존재하는 경우라 했다.
즉, 위상 정렬을 적용하던 중 모든 정점을 방문하지 않고 큐가 비어 종료된 경우이다.


※ 조건 : "?"를 출력
그래프에 따라 위상 정렬은 2개 이상의 결과를 낼 수 있다.
이는 2개 이상의 정점이 동시에 진입 차수가 0이 될 때 발생하며, 
따라서 위상 정렬을 적용하던 도중 큐의 크기가 2 이상인 경우이다.











