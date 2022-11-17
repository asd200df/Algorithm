1288. 새로운 불면증 치료법

방법[1]
0 input 받기 & parsing 함수 맹글기 & used[] 맹글기 & while 맹글기
	cnt = 0, ret = 1; 
// 1 while 함수 시작 parsing 함수 호출 거기로 보냄 
// 	% 10 >> /= 10 사용해서 들어있는 숫자 하나씩 dat[] = 1 넣음
1 while 함수 시작 parsing 함수 호출 거기로 보냄 
	to_string 하고 int(강제 형변환)으로 used[] = 1 넣음
2 used 검사 0 ~ 9 까지 모두가 1로 체크 되어있는지
3 되어 있으면 바로 종료 break;
4 안되어 있으면 N x 2 해서 증가시키고 ret++ 
	다시 while문 첫번째로 이동해서 반복  
5 while 문 밖에 cout << ret 출력하고 끝 
+@ init 함수 등


[input]
5
1
2
11
1295
1692

[output]
#1 10
#2 90
#3 110
#4 6475
#5 5076

