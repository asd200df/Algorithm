// 오큰수 (17298) Gold[4] 설계




#1 (실패)
1) input() && solution()
2) stack 이용
	// 조건을 어떻게 ? 
	// 작거나 같은 거 나오면 스택에 담고
	// 큰 거 나오면 스택 pop하면서 그 갯수만큼 큰 거 출력 하고 그 큰 거 스택에 담아
	// 반복

3 4 5 2 7
3 2 1 5 2

321 5



#2 
// stack 2개 사용해서 value 와 index 담기
// 작거나 같은 거 나오면 value stack 과 index 스택에 각 각 담고
// 더 큰 거 나오면 value 스택에서 하나씩 빼면서 해당 index 스택에 있는 index 를 이요해서
// 결과를 출력할 배열에 담음 vector에 담는게 더 효율적이겠네요 
// value 스택에서 하나씩 빼다가 value 스택에 있는게 더 크면 멈춰야 되고 
// 다 돌고 나왔는데 남아 있으면 해당 index 스택에서 index 꺼내서 -1 넣어주면 ? 완성 !


