// 유전법칙 (PCCP 모의 1회) 설계
// 미완성



RR >> 1 ~ (n-2) * 4
Rr >> ((n-2) * 4) + 1 ~ ?
rr >> ? ~ 4^(n-1)

여기서 중요한 건 Rr 이잖아 
Rr 도 근데 RR Rr Rr rr 이걸 0 1 2 3 이라고 생각해봐 
그럼 (일단 Rr 범위 안에 있다는 가정하에) p % 4 하면 나오는 숫자가 답인거지 
... RR Rr Rr rr RR Rr Rr rr ...
    5  6 7  8  9 10 11 12
ex) 10번째꺼 알고싶어 10%4 == 2고 2는 Rr 맞잖아 이렇게 해야 되는거지 

lev
1				Rr
2	RR		Rr		Rr		rr	      == 4
3	RR RR RR RR 	RR Rr Rr rr	RR Rr Rr rr	rr rr rr rr   == 16
4 	RRRR..  (16)	RR Rr .. (16)	RR Rr .. (16)	rrrr (16)     == 64	
...					~ (48)
범위 설정
Lev 1 == n1, p1 Rr
Lev 2 == n2, p1 RR / n2, p2 Rr / n2, p3 Rr / n2, p4 rr
Lev 3 부터는 계산법 이용
RR  :	1			~	4^(lev - 2)
Rr  :	4^(lev - 2) + 1		~	4^(lev - 2) * 3
rr  :	4^(lev - 2) * 3 + 1	~	4^(lev - 1) 




