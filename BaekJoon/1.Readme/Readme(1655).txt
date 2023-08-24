// 가운데를 말해요 (1655) Gold[2]



#1 (시간 초과)
vector sort 하고 중간값 꺼내는 방식



#2 
priority queue 2개 만들어서 큰값 작은값 넣고 
가운데 값 출력하는 방식 
DESC >> 중간과 중간 보다 앞 부분 담당
ASC >> 중간 보다 뒷 부분 담당
DESC PQ 의 top 이 중간값이 되게끔 만들기 
규칙 1. DESC pq 원소가 ASC pq 원소 보다 1개 더 많거나 같아야 한다 
규칙 2. DESC pq top 값이 ASC pq top 값 보다 작아야 한다 // 아니라면 top 끼리 swap 진행 

진행하면 
1 2 3 4 5
D 3 2 1
A 4 5
이런 식으로 들어가짐 







