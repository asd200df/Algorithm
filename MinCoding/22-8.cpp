#include <iostream>
using namespace std;

int main()
{
	int vect[3][2][2] = {
		{{2, 4}, {1, 5}},
		{{2, 3}, {3, 6}},
		{{7, 3}, {1, 5}},
	};

	int x, y, input;
	int max = -99;
	int min = 99;

	cin >> input;

	for (y = 0; y < 2; y++)
	{
		for (x = 0; x < 2; x++)
		{
			if (vect[input][y][x] > max) max = vect[input][y][x];
			if (vect[input][y][x] < min) min = vect[input][y][x];
		}
	}

	cout << "MAX=" << max << endl;
	cout << "MIN=" << min << endl;

	return 0;
}