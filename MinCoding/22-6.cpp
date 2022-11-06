#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[4][10];

	for (int i = 0; i < 4; i++)
	{
		cin >> str[i];
	}

	int max = -99;
	int min = 99;

	int maxIndex;
	int minIndex;


	for (int i = 0; i < 4; i++)
	{
		int len = strlen(str[i]);

		if (max < len)
		{
			max = len;
			maxIndex = i;
		}

		if (min > len)
		{
			min = len;
			minIndex = i;
		}
	}

	cout << "긴문장:" << maxIndex << endl;
	cout << "짧은문장:" << minIndex << endl;
}