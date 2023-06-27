// 두 수의 합 (3273) Silver[3]

Find rule
1 2 3 5 7 9 10 11 12
[13]
1 12

#1 // 실패
1) input() arr[1 <= n <= 1000000]
2) solve()
	sort()
	for(int i = 0; i < N / 2; i++)
		TwoPointer(arr[i], arr[(n-1)-i])
3) TwoPointer
	값 두개 더해서 target에 맞으면 cnt++;
4) cnt 출력 !

5 / 2 = 2
0 1 2 3 4
6 / 2 = 3
0 1 2 3 4 5


#2 // 성공
1) input() arr[1 <= n <= 1000000]
2) solve()
	sort()
3) TwoPointer
	while(left < right)
		== target { cnt++ }
		< target { left++ }
		> target { right-- }
4) cnt 출력 !


