// 올림픽 (8979) Silver[5]

#1 
1) input () // 1 <= N <= 1000, K
	struct (country gold silver bronze), vector<struct>
2) solve ()
	sort(vector.begin(), vector.end(), compare) 
	// compare 써서 금, 은, 동 순위 매겨야함
3) for 문 처음부터 돌면서 순위 ++ but 공동 순위 나오면 증가 안함
	그래도 공동 순위 다음은 증가 안한 것도 포함해야되는 거 알지 ?? 
	ex) 1 2 공동 3, 3 이면 그 다음 5등임
 	K 국가 나오면 그 순위 출력 !

1 2 2 2 5
r 1 2 2 3
t 0 1 2
1 2 2 2 5
5 3
1 1 0 0
2 0 1 0
3 0 0 1
4 0 1 0
5 0 1 0







