// 연구소 (14502) Gold[4]



#1 
input에서 애초에, 바이러스 위치랑 0(빈 칸) 갯수 저장해 놔야 함 
DFS() 로 비어있는 곳 중 세 곳을 벽으로 바꾸고 
BFS() 로 바이러스 퍼트림 퍼트리면서 숫자 세고,
전체 0수에서 바이러스 숫자 빼주면 남은 안전구역 수 나오고
그 중 최댓값 저장해서 출력