2112. ��ȣ �ʸ�


���� Ư���� ����(A, B) �β� D�� ���� ũ�� W�� ������ �Է� �ް�
���η� �հ� ���� K��(K���� Ư���� ��������)�� �����ϴµ� 
A ��ǰ�̳� B ��ǰ�� �ѷ��� �� ���� Ư���� A�� B�� �ٲ� �� ����
�� ��ǰ�� �ּҷ� �ѷ��� �հ� ��Ű�� �����ž�  
�׷��� �� �ּ� ��ǰ ��� ���� ���Ͻÿ��� ���� (0 ���� �� ������ ����)


���[1] (�ٽ� �ؾ� ��)
0 input �ޱ� tc >> D >> W >> K >> ...
1 ���� 2���� �迭�� �ޱ� map[3<=13][1<=20]
2 DFS �Լ� �ͱ۱� 
3 DFS() 
	���� ���� �� : �迭 ���η� �� �پ� ���� �Ǹ� flag = 1
	if(flag == 1) minimum ���� & ���� ���ְ� return
	for (i 0~1){
		if 0 >> for(i < D){ // A = 0
			DFS(fill(&arr[][0], &arr[][W + 1], 0));
		}
		else { // B = 1
			for(i < D){
			DFS(fill(&arr[][0], &arr[][W + 1], 1));
		}
	}



* fill(&arr[2][0], &arr[2][5], 1);
	// (�����ּ�, ���ּ� + 1, �ʱ�ȭ ��); �� ���·� ����
	// memset ���� ���� 0���� �ۿ� �ʱ�ȭ�� �ȵ� 

* copy(&arr[0][0], &arr[A][B], &brr[0][0]);
	// arr �迭�� 0, 0 ���� A, B ���� brr �迭�� 0, 0���� �ٿ�����

@ back tracking & minimum start & pick
	back tracking { 
		1 ���� ���� ���� �� >> ���� ����
		2 ���� ������ ��ȯ (�뵵�� �°�)
		3 �����̳� ���� ���
		4 �ٽ� ������ ���� �ǵ��� ����
	 } 


���[2] (39/50 ����)
0 input �ޱ� tc >> D >> W >> K >> ...
1 ���� 2���� �迭�� �ޱ� map[3<=13][1<=20]
2 �Լ� �ͱ۱�
	init func (initialization �Լ�)
	DFS func (dfs Ž��)
	back tracking func (map �����ߴٰ� �ǵ����� �Լ�)
	solve func (������ �ϳ��� ������ �Լ�)
	isValid func (��ȿ���� Ȯ���� �� �Լ�)
3 solve() {
	isValid() call 0������ ���� ������ �ٷ� return;
	�ȸ����� for limit 0~D(�β� ����)���� ���鼭 
		DFS(limit) ȣ��
4 DFS(int now, int limit, int line(�� ��°�� �ٲ��ٷ�)
	, int AB(A or B), int start(start point)){
	// map �ٲ����� fill() ���
	
	if(now == limit){ // DFS�� ȣ���� ���� limit�� ������ �˻� 
		isValid() �˻� �ߴµ� �ȵǸ� ���� ���ϰ� ����
			�˻� �ߴµ� �Ǹ� minimum �̶� �� �� ����
		backtracking func ȣ���ؼ� map�� ���� ����
		return;
	}

	for(0~1){ // A or B 
		if 0 >> for(i = start ~ D){
			DFS(now + 1, limit, i, 0, i + 1);						
		}
		else 1 >> for(i = strat ~ D){
			DFS(now + 1, limit, i, 1, i + 1);	
		}
	}
}



���[3] DFS����
0 input �ޱ� tc >> D >> W >> K >> ...
1 ���� 2���� �迭�� �ޱ� map[3<=13][1<=20]
2 �Լ� �ͱ۱�
	init func (initialization �Լ�)
	DFS func (dfs Ž��)
	back tracking func (map �����ߴٰ� �ǵ����� �Լ�)
	solve func (������ �ϳ��� ������ �Լ�)
	isValid func (��ȿ���� Ȯ���� �� �Լ�)
3 solve() {
	isValid() call 0������ ���� ������ �ٷ� return;
	�ȸ����� for limit 0~D(�β� ����)���� ���鼭 
		DFS(limit) ȣ��
4 DFS(int now, int limit, int line(�� ��°�� �ٲ��ٷ�)
	, int AB(A or B), int start(start point)){

	�迭�� line �ϳ��� �����ؼ� ������ �־�� �� 
	�׸��� ���� type���� �ٲ������� ������ �־�� �� 
	
	if(now == limit){ // DFS�� ȣ���� ���� limit�� ������ �˻� 
		���⼭ line�̶� type ���� ������ �ִ� ��
		 ������ map �ٲ���		
		�� ����
		isValid() �˻� �ߴµ� �ȵǸ� ���� ���ϰ� ����
			�˻� �ߴµ� �Ǹ� minimum �̶� �� �� ����
		backtracking func ȣ���ؼ� map�� ���� ����
		return;
	}

	for(0~1){ // A or B 
		if 0 >> for(i = start ~ D){
			DFS(now + 1, limit, i, 0, i + 1);						
		}
		else 1 >> for(i = strat ~ D){
			DFS(now + 1, limit, i, 1, i + 1);	
		}
	}
}




[input]

10        		// testcase   
6 8 3         		// �β� D, ���� ũ�� W, �հ� ���� K
0 0 1 0 1 0 0 1		// ������ Ư�� A = 0, B = 1
0 1 0 0 0 1 1 1
0 1 1 1 0 0 0 0
1 1 1 1 0 0 0 1
0 1 1 0 1 0 0 1
1 0 1 0 1 1 0 1

6 8 3         
1 1 1 1 0 0 1 0
0 0 1 1 0 1 0 1
1 1 1 1 0 0 1 0
1 1 1 0 0 1 1 0
1 1 0 1 1 1 1 0
1 1 1 0 0 1 1 0
...


[output]
#1 2
#2 0




[debug]
1
6 4 4
1 1 0 0
0 1 0 1
0 0 0 1
1 1 1 1
1 1 0 1
1 0 1 0

2





