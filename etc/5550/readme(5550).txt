
이 문자열은 ‘c’, ‘r’, ‘o’, ‘a’, ‘k’로만 이루어져 있다.

불가능한 경우 -1을 출력



방법[1] 실패 (알파벳 순서가 달라고 갯수를 count 함)
1 frog[] 배열 크게 만들고
2 test case & input(string으로) 받음
3 string 으로 받은 문자열 for문으로 한 글자씩 탐색하면서 dat로 카운터함
	frog[dat]++; 이렇게
4 forg['c'] ['r'] ['o' ... 중 가장 작은 숫자 출력함
	but 가장 작은 숫자가 0일 경우에는 -1을 출력함


* 동시에 우는 경우만 세는거야
crcoarkcoroakak
12 34 5
  1  2  3  45
       1 23  45
12345가 3개지만 답은 2야 왜 ? 처음 12345가 끝나기 전에 겹쳐서
 등장한 12345는 1개이기 때문에 두마리라고 보는거지 


crcoark/	coroakak
12 34 5/	
  1  2 /	 3  45
       /	1 23  45


방법[2] 실패 (DFS는 완탐 ... 필요가 없음)
1 used[2501] 배열 크게 만들고
2 test case & input(string으로) 받음
3 완성되는 croak 가 하나라도 있는지 부터 보고 있으면 다음 단계로
	없으면 -1 출력 후 종료
4 처음 완성되는 croak의 k의 인덱스를 저장
5 처음 c부터 k 인덱스까지 c 가 몇 개 더 있는지 봄
	(c만 일단 나오면 그 뒤에 문자는 k 인덱스를 넘어서 있는 것이 가능 고려)
6 DFS 함수 호출 후 그 갯수 만큼 DFS 돔 
	(used 사용하면서)
7 갯수 정해지면 리턴
8 main에서 출력


방법[3]
1 used[2501] 배열 크게 만들고
2 test case & input(string으로) 받음
3 완성되는 croak 가 하나라도 있는지 부터 보고 있으면 다음 단계로
	없으면 -1 출력 후 종료
4 처음 완성되는 croak의 k의 인덱스를 저장
5 처음 c부터 k 인덱스까지 c 가 몇 개 더 있는지 봄
	(c만 일단 나오면 그 뒤에 문자는 k 인덱스를 넘어서 있는 것이 가능 고려)
6 for (i = 1; i < 센 갯수(k index까지 c 갯수); i++) 하면서
	"roak"를 찾음
7 찾으면 used 체크 해주고 또 못 사용하게 해줌
8 완성되는 거 몇 개인지 /* + 1(first croak) */ 을 결과 값으로 출력


[input]
8
crcoarkcoroakak
ccccrrrrooooaaaakkkk
karoc

[output]
#1 2
#2 4
#3 -1 ...  
































