이 문제의 목적은 경로나 원소를 구하는게 아니야
최장 길이만 구하면 되는 문제야 


이진탐색으로 더 효율적으로 target 찾기 


vector 
L	M	R 
0	/2	vector.size() - 1 


배열 보단 벡터가 컨트롤하기 더 편하다는 것을 인지하기 !

value	1 2 3 4 5
idx 	0 1 2 3 4
	0   4/2   5-1


1 3 1 2 5


mid = left + (right - left) / 2;
1 2 3 4 5
0 1 2 3 4 

left = 0 min = 2 right = 4
0 + (4-0) / 2 = 2

left = 2 mid = 3 right = 4
2 + (4-2) / 2 = 2 ?











