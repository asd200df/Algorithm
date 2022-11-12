2112. 보호 필름


여러 특성을 가진(A, B) 두께 D에 가로 크기 W의 셀들을 입력 받고
세로로 합격 기준 K개(K개의 특성이 동일한지)를 만족하는데 
A 약품이나 B 약품을 뿌려서 한 줄의 특성을 A나 B로 바꿀 수 있음
그 약품을 최소로 뿌려서 합격 시키고 싶은거야  
그래서 그 최소 약품 사용 수를 구하시오가 문제 (0 번일 수 있음을 인지)


방법[1] (다시 해야 돼)
0 input 받기 tc >> D >> W >> K >> ...
1 쉘들 2차원 배열에 받기 map[3<=13][1<=20]
2 DFS 함수 맹글기 
3 DFS() 
	종료 조건 전 : 배열 세로로 한 줄씩 보고 되면 flag = 1
	if(flag == 1) minimum 갱신 & 무시 해주고 return
	for (i 0~1){
		if 0 >> for(i < D){ // A = 0
			DFS(fill(&arr[][0], &arr[][W + 1], 0));
		}
		else { // B = 1
			for(i < D){
			DFS(fill(&arr[][0], &arr[][W + 1], 1));
		}
	}



* fill(&arr[2][0], &arr[2][5], 1);
	// (시작주소, 끝주소 + 1, 초기화 값); 이 형태로 가능
	// memset 같은 경우는 0으로 밖에 초기화가 안됨 

* copy(&arr[0][0], &arr[A][B], &brr[0][0]);
	// arr 배열의 0, 0 부터 A, B 까지 brr 배열의 0, 0부터 붙여넣음

@ back tracking & minimum start & pick
	back tracking { 
		1 종료 조건 도달 시 >> 정보 저장
		2 원래 정보를 변환 (용도에 맞게)
		3 조건이나 정보 얻고
		4 다시 저장한 정보 되돌려 놓기
	 } 


방법[2] (39/50 실패)
0 input 받기 tc >> D >> W >> K >> ...
1 쉘들 2차원 배열에 받기 map[3<=13][1<=20]
2 함수 맹글기
	init func (initialization 함수)
	DFS func (dfs 탐색)
	back tracking func (map 저장했다가 되돌려줄 함수)
	solve func (갯수를 하나씩 보내줄 함수)
	isValid func (유효한지 확인해 줄 함수)
3 solve() {
	isValid() call 0개에서 부터 맞으면 바로 return;
	안맞으면 for limit 0~D(두께 갯수)까지 돌면서 
		DFS(limit) 호출
4 DFS(int now, int limit, int line(몇 번째줄 바꿔줄래)
	, int AB(A or B), int start(start point)){
	// map 바꿔주자 fill() 사용
	
	if(now == limit){ // DFS를 호출할 때의 limit과 같으면 검사 
		isValid() 검사 했는데 안되면 갱신 안하고 무시
			검사 했는데 되면 minimum 이랑 비교 후 갱신
		backtracking func 호출해서 map되 돌려 놓음
		return;
	}

	for(0~1){ // A or B 
		if 0 >> for(i = start ~ D){
			DFS(now + 1, limit, i, 0, i + 1);						
		}
		else 1 >> for(i = strat ~ D){
			DFS(now + 1, limit, i, 1, i + 1);	
		}
	}
}



방법[3] DFS수정
0 input 받기 tc >> D >> W >> K >> ...
1 쉘들 2차원 배열에 받기 map[3<=13][1<=20]
2 함수 맹글기
	init func (initialization 함수)
	DFS func (dfs 탐색)
	back tracking func (map 저장했다가 되돌려줄 함수)
	solve func (갯수를 하나씩 보내줄 함수)
	isValid func (유효한지 확인해 줄 함수)
3 solve() {
	isValid() call 0개에서 부터 맞으면 바로 return;
	안맞으면 for limit 0~D(두께 갯수)까지 돌면서 
		DFS(limit) 호출
4 DFS(int now, int limit, int line(몇 번째줄 바꿔줄래)
	, int AB(A or B), int start(start point)){

	배열에 line 하나씩 저장해서 가지고 있어야 함 
	그리고 무슨 type으로 바꿔줄지도 가지고 있어야 함 
	
	if(now == limit){ // DFS를 호출할 때의 limit과 같으면 검사 
		여기서 line이랑 type 정보 가지고 있던 거
		 꺼내서 map 바꿔줘		
		그 다음
		isValid() 검사 했는데 안되면 갱신 안하고 무시
			검사 했는데 되면 minimum 이랑 비교 후 갱신
		backtracking func 호출해서 map되 돌려 놓음
		return;
	}

	for(0~1){ // A or B 
		if 0 >> for(i = start ~ D){
			DFS(now + 1, limit, i, 0, i + 1);						
		}
		else 1 >> for(i = strat ~ D){
			DFS(now + 1, limit, i, 1, i + 1);	
		}
	}
}




[input]

10        		// testcase   
6 8 3         		// 두께 D, 가로 크기 W, 합격 기준 K
0 0 1 0 1 0 0 1		// 셀들의 특성 A = 0, B = 1
0 1 0 0 0 1 1 1
0 1 1 1 0 0 0 0
1 1 1 1 0 0 0 1
0 1 1 0 1 0 0 1
1 0 1 0 1 1 0 1

6 8 3         
1 1 1 1 0 0 1 0
0 0 1 1 0 1 0 1
1 1 1 1 0 0 1 0
1 1 1 0 0 1 1 0
1 1 0 1 1 1 1 0
1 1 1 0 0 1 1 0
...


[output]
#1 2
#2 0




[debug]
1
6 4 4
1 1 0 0
0 1 0 1
0 0 0 1
1 1 1 1
1 1 0 1
1 0 1 0

2





