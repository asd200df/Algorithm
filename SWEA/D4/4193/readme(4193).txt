4193. ������ȸ ����� (���� Ž�� + ����)

[����]
N*N map (2<=N<=15)
������ �� �ִ� �� : 0
������ �� ���� �� : 1
2�� �ֱ��� �ҿ뵹�� : 2 ()
���� ��ǥ, ���� ��ǥ �־���
>> ���� ���� ��� �������� �� �� �ʸ��� �����ұ� ?
	���� �� �� ���ٸ� -1�� ����϶� !


����[1] ����(3/15)
0 input
1 make func
	input()
	solve()
	init()
	BFS()
	vortex()
2 BFS()
	4���⿡ +1(���ڸ�) ���� ����
3 vortex()
	map�� �ִ� �ҿ뵹�̵��� 2�� ���� ������ �� �ִ� ��� ��ȯ
	�ٽ� �� �� �ٽ� �������� ���ϴ� ��� 2�� ���� ��Ŵ 
e print >> result !



����[2] (����)
0 input
1 make func
	input()
	solve()
	init()
	BFS()
	MapChange()
2 solve(){
	1 MapChange func call
	2 BFS func call
	3 Second++
	4 ���� flag == 1 return Second
 }



����[3] (���ͽ�Ʈ�� & BFS)
0 input
1 make func
	input()
	solve()
	init()
	BFS()
2 map size ���� ������� sum array ����
	�̴ϸ� �����ϱ� 
3 BFS(){
	que.push start;
	while()
		now << ���� & pop	
		for(4 direct){
			ny & nx
			1. < map < continue
			2. map[ny][nx] == 1 continue
			3. map[ny][nx] == 2 
				tmp = ���� ���� + �ҿ뵹�� ���
				if(tmp < ����) 
					���� ����	
					que.push
			4. else
				���� + 1
				que.push
			5. ��Ž �� >> ����
		}
 }
end ���ϴ� ���� ������ sum array�� ������ ��ǥ �̴ϸ� �� ��� !



[input]
3  // test case
5  // N
0 0 0 0 0
0 0 0 1 0
0 0 0 1 0
2 2 1 1 0
0 0 0 0 0
4 0  // ������
2 0  // ������

[output]
#1 4


now.sec ���� �ʰ� �ƴϾ� ���� ���� �ʾ� ���� !
2 �״ϱ� �� �� now.sec�� 1�ΰ��� 
5	4
8	7
11	10
14 	13
17	16








