// 최솟값 찾기 (11003) Platinum[5]



#0 문제 이해하기

Di = Ai-L+1 ~ Ai 중 최솟값이래
1 5 2 3 6 2 3
0 1 2 3 4 5 6
 ㅇㅇㅇ
1 1 1 2 2 2 2 2 3 3 2 2



#1 (3% 시간 초과)
pq(priority_que) 와 dq(deque) 사용하기
dq로 하나씩 담고 L 길이 만큼 되었을 때 하나씩 pop
pq는 현재 가지고 있는 값중에 최솟값이 무엇인지 알려줌 
그리고 dq에서 하나씩 pop 될 때 pq에서도 해당 숫자 pop 해주는 것이 포인트인데 
어려워 보임 ... 



#2 (83% 시간 초과...)
슬라이딩 윈도우  && deque 사용해보기 
룰 첫번째, 항상 dq.front() 출력 !
두번째, 오른쪽으로 한 칸씩 들어오고 왼쪽으로 한칸씩 나가는 거 구현
세번째, 들어오는 값이 더 크면 그냥 담고 더 작으면 보다 큰 애들다 pop 시켜서 빼



#3 (X struct 말고 pair 사용해야 돼)
sturct 와 priority_que 이용해서 값 뿐만 아니라 인덱스도 같이 담아 
그냥 단순하게 하나씩 담고 출력을 하기 전에 
top() 에 이미 나갔어야 할 인덱스 있으면 다 빼버리고
마지막에 top 을 출력하는 방식으로 



#4 맞았습니다 !!
pair && priority_queue 사용하고
값이랑 인덱스 같이 담고 
출력 전 top().second (== index)가 나갔어야 할 친구면 다 pop 시키고
다 pop 시켰으면 top() 출력하면 됨 



