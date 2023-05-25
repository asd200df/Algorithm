좌석 관리 [21년 재직자 대회 예선]

# 문제 이해 
1이 in 됐을 때 
1 gets the seat (1, 1). 

2가 out 했을 때 
2 leaves from the seat (1, 3).

3이 in 했는데 다시 in 했을 때 
3 already seated.

4가 out 다음 또 out 했을 때 
4 already left seat.

5가 in 없이 out만 하려고 할 때 
5 didn't eat lunch. 
( used[id] == 0 && visit[id] == 0 )

6이 in 하고 out 했는데 다시 in 하려고 할 때  ( if-out 에서 1처리 요망 )
6 already ate lunch.

누군가 in 하려고 했는데 자리가 꽉 찼을 경우 
There are no more seats. 

#1
1. insol() -> N, M 행렬 / Q개의 명령 / 1 <= id <= 10000
	map, used, 
2. 입력 받으면 map 바꾸고 used check 하고 -> 결과 출력 -> Recycle
※ 제일 처음 좌표가 1, 1 인 것 주의하기 & map 테두리에 벽을 의미의 숫자 지정해서 넣기

※ queue에 비어있는 자리 push 해 놓고 하나씩 pop 해서 쓰고 
 다시 자리가 비면 push 해서 사용 queue < struct > y, x ; 

※ struct array 사용하기 

※ 안전도가 높은 순서대로 앉혀야 됨 (복병...;;)
