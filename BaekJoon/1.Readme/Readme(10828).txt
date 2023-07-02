// 스택 (10828) Silver[4] 설계

#1
1) init() 
	// initialization Function
	// unordered_map<string, int> 넣어놓음 >> switch 사용 위해
	// ex) um["push"] = 1;
2) input() 
	N만 받음
3) solve()
	unordered_map에 미리 정의해 놓은 번호 따라 가게끔
	ex) push >> 1
	switch()
		push
		pop
		size
		empty
		top
	※ 각 각 break; 적어주는 거 잊지 말고 & push는 추가 숫자 입력 받아야