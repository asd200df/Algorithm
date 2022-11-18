4193. 수영대회 결승전 (완전 탐색 + 구현)

[문제]
N*N map (2<=N<=15)
지나갈 수 있는 길 : 0
지나갈 수 없는 길 : 1
2초 주기의 소용돌이 : 2 ()
시작 좌표, 도착 좌표 주어짐
>> 가장 빠른 길로 수영했을 때 몇 초만에 도착할까 ?
	도착 할 수 없다면 -1을 출력하라 !


설계[1] 실패(3/15)
0 input
1 make func
	input()
	solve()
	init()
	BFS()
	vortex()
2 BFS()
	4방향에 +1(제자리) 까지 구현
3 vortex()
	map에 있는 소용돌이들을 2초 마다 지나갈 수 있는 길로 변환
	다시 그 후 다시 지나가지 못하는 길로 2초 유지 시킴 
e print >> result !



설계[2] (보류)
0 input
1 make func
	input()
	solve()
	init()
	BFS()
	MapChange()
2 solve(){
	1 MapChange func call
	2 BFS func call
	3 Second++
	4 도착 flag == 1 return Second
 }



설계[3] (다익스트라 & BFS)
0 input
1 make func
	input()
	solve()
	init()
	BFS()
2 map size 같은 사이즈로 sum array 생성
	미니멈 갱신하기 
3 BFS(){
	que.push start;
	while()
		now << 갱신 & pop	
		for(4 direct){
			ny & nx
			1. < map < continue
			2. map[ny][nx] == 1 continue
			3. map[ny][nx] == 2 
				tmp = 다익 현재 + 소용돌이 계산
				if(tmp < 다익) 
					다익 갱신	
					que.push
			4. else
				다익 + 1
				que.push
			5. 완탐 후 >> 종료
		}
 }
end 원하는 곳에 도착시 sum array에 목적지 좌표 미니멈 값 출력 !



[input]
3  // test case
5  // N
0 0 0 0 0
0 0 0 1 0
0 0 0 1 0
2 2 1 1 0
0 0 0 0 0
4 0  // 시작점
2 0  // 도착점

[output]
#1 4


now.sec 다음 초가 아니야 지금 현재 초야 인지 !
2 그니까 이 때 now.sec은 1인거지 
5	4
8	7
11	10
14 	13
17	16








