동계 테스트 시점 예측 문제 설계


#1 (시간제한 초과) (5/11)
※ 처음 = 공기 0, 얼음 1 >> 변경할 수 = 외부 공기 2, 내부 공기 0, 얼음 1 
1. input() 받기 
	얼음 위치를 queue<struct> 로 담아놔 
2. 내부공간 외부공간 구분을 하기 위해 외부공간 Floodfill >> 숫자를 바꿈 2로
3. 일단 time++ 한 뒤 (시간이 흐름을 의미)
	queue의 얼음 위치를 하나씩 꺼내면서 그 좌표의 얼음 4방향 search 
	>> 2방향 이상이 외부 공기(2)면 그 위치 다른 queue2 에 저장해 놓고 
	>> 외부 공기(2)로 숫자 변경
	※ [주의] 찾으면서 외부공기로 바꾸면 다 외부공기로 바뀔 가능성 있음 
4. 다시 2.로 가서 Floodfill 로 외부공기 갱신해주고 3.으로 가서 반복
	결국 얼음 위치를 넣는 queue가 empty()면 종료
5. time 출력 !



#2 (맞았당 !)
최적화 
for문 줄이기 & map change 함수 삭제

