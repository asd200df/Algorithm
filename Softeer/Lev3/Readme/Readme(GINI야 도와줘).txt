// GINI야 도와줘 문제 설계


※ Function에서 queue도 변수처럼 return이 된다는 것 인지하기 


# 1 (Fail)
1) input 받기
	struct 
2) solve()
	1. Rain() >> BFS 1 cycle 
		map change
	2. BFS() >> BFS 1 cycle
		cnt
3) return result


#2 (시간초과)
1) input 받기
2) solve() 
	1. Rain() >> 1 cycle search >> que 담고 return
	2. return 받은 que 가지고 MapChange();
	3. Ego() >> 1 cycle search >> que 담고 return
	4. return 받은 que 가지고 MapChange();
3) if 도착시 result return >> cout !



if (map[ny][nx] == 'U') {
				// 사람이 먼저 이동하고 비 맞았을 때 ego_que에서 빼줘야 함 맞으면 바로 FAIL 
			} 



이거 FAIL 나와야 돼 
5 5
H...*
.....
X..XX
W....
....*


# 3 (정답)
2 + map change 없이 used 사용으로 시간 줄이기 +  for ( queue.size() ) 로 한 바퀴씩 돌기 
