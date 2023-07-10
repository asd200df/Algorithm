// 나무 자르기 (2805) Silver[2]




#1 // 문제 이해 잘못한듯
1) input()
	// N <= 1,000,000	/ M <= 2,000,000,000
2) solve()
	sort() // ASC 
	for(int limit = 나무중 가장 큰 거 , > 0, limit--)
		BS(limit) // binary search
3) BS()
	limit 보다 큰 거 다 저장해서 목표치와 같거나 크면 limit >> 결과 변수에 저장 flag = 1
	목표치와 같지 않으면 flag = 0
4) 다시 solve() 로 돌아와서 flag 1 이냐 0이냐에 따라 진행 
5) 결과 변수에 담겨 있는 것 출력 !

※ 절단기 높이 정수 또는 0도 가능




#2 (실패 : 시간초과) // upper bound && lower bound 사용 해보기 !
1) input()
2) solve()
	sort() // ASC
	for(int limit = 나무중 가장 큰 거 , >= 0, limit--)
		valid check()
3) bool >> valid check
	upper bound 사용해서 limit 보다 큰 거 잘라서 sum 비교 후 
	true or false return !
4) false 면 solve에 for문 계속 진행 true 면 break 후 결과 출력 !




#3 // binary search 를 하는데 0 부터 입력 될 수 있는 나무 최대 높이로 하는거지 
1) input()	// M <= 2,000,000,000	// N <= 1,000,000
2) solve()
	// 할 필요가 없네 ;; sort() // ASC
	L = 0, R = 입력 될 수 있는 나무 최대 높이
	while(L < R){	
		sum = 0 ; mid = ;
		binary search 진행
		if(mid < 입력 받은 나무중 가장 큰 거) {
			if (valid check () )  { maximum 갱신 } 
		}
		if(mid == sum) {  정답 & break; } 
		else if(mid < sum) { maxi 갱신 & R = mid - 1; }
		else // mid > sum { L = mid + 1; }
	}
3) maximum 출력 !

















