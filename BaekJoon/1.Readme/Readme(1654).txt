// 랜선 자르기 (1654) Silver[2]




#1 실패(50% 정답)	// Binary Search && Upper_bound 사용해보기 
1) input()
	// K <= 10,000 // N <= 1,000,000
2) solve()
	sort() !

	left = 0; right = 입력 중 가장 긴 길이;
	while{
		binary search 진행
		upper_bound 사용해서 몇 개 만들 수 있는지 체크
	}
3) print 결과 



#2 (같은 점수)
// 같은 코드에 upper_bound 빼 보기 



#3 (같은 점수)
// 타입 바꿔보기 int >> long long 으로 ( K <= 10,000 // N <= 1,000,000 )



#4 (런타임 에러 (Division By Zero))
// lower_bound 로 변경



#5 (정답)
// left 시작을 0부터가 아니라 1부터 시작해야 됨
// upper_bound 쓰면 틀리고 >> 입력이 모두 같은 수 일 때 마지막꺼만 봄
// lower_bound 는 정답이지만, 시간 차이가 없음 ,,, 



