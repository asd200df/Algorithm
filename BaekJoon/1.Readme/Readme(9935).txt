// 문자열 폭발 (9935) Gold[4] 설계



# 1 (구현실패)
1) input()
	// deque 에 push_back;
	// target 문자열 저장해 놓고
2) solve()
	deque 하나 더 만들고
	while(flag){
		deque1 에서 front pop >> target 길이 만큼
		맞으면 없애고 아니면 다시 deque2 에 push_back 
		반복하다가 더 이상 바꿀 것이 없으면 break;
3) deque 에 남아 있는 것 출력 ! 
	※ 마지막에 deque 에 남아있는 거 없으면 FRULA 출력 !
	


# 2 
1) input()
	// stack 사용하기
2) solve()
	// 단순하게 string 에 입력 받고 받은 거 2차원 for문으로 돌면서 stack에 저장하는 거
	// 시간 초과 날 가능성도 있어 보임 ;;;
3) deque 에 남아 있는 것 출력 ! 
	※ 마지막에 stack 에 남아있는 거 없으면 FRULA 출력 !



# 3 (성공)
1) input()
2) solve()
	// for 임시 stack에 뒤에서 부터 하나씩 넣어
	//	for 그걸로 폭탄이랑 비교 (거꾸로 비교해야 돼)
	// ex) inp = c44, 폭탄 = c4 면 stack = 44c 이렇게 추가하면서 폭탄도 4c 이렇게
	//		맞으면 폭탄 사이즈 만큼 pop, 아니면 계속 진행
	//  다 돌고 나오면 stack에 들어있는게 남아 있는 거고
3) stack 에서 하나씩 꺼내면서 출력 끝 ! 
	
※ 남아 있는 것 중에 폭탄 문자가 있어서 탐색문 전체를 while 문에 넣고 
	탐색문 지났는데 바뀐게 없어야 나오도록 하니까 통과 !







