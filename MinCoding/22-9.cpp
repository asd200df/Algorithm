#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char vect[5][10] = {
		"Jason",
		"Dr.tom",
		"EXEXI",
		"GK12P",
		"POW"
	};

	char input[10];

	cin >> input;
	int flag = 0;
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(vect[i], input) == 0)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1) cout << "��ȣ����";
	else cout << "��ȣƲ��";

	return 0;
}