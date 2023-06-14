// 숫자 카드 2 (10816) 
// Silver[4]
// Binary Search & sort & Data Structure & Hash Map


// [실패]
# 1 // Binary Search & Hash Map
1) input >> Nrr, Mrr
2) sort(); >> Nrr
3) 이분탐색 >> Unordered_Map 에 Count
4) Result Print ! 
	>> for(i < M) cout >> UM[Mrr] 
※ hash map 


// [정답]
# 2 // upper/lower bound & Hash Map
1) input >> Nrr, Mrr
2) sort(); >> Nrr
3) 이분탐색 >> 있으면 4번으로 없으면 continue
4) upper_bound & lower_bound 
5) Result Print ! 
	>> for(i < M) cout >> UM[Mrr] 
