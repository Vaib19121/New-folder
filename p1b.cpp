#include <bits/stdc++.h>
using namespace std;

int main()
{
	char matrix[5][5] = {{'m', 'o', 'n', 'a', 'r'}, {'c', 'h', 'y', 'b', 'd'}, {'e', 'f', 'g', 'i', 'k'}, {'l', 'p', 'q', 's', 't'}, {'u', 'v', 'w', 'x', 'z'}};
	char pt[10];
	int i, j, row1 = 0, row2 = 0, col1 = 0, col2 = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Enter the plain text" << endl;
	cin >> pt;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (matrix[i][j] == pt[0])
			{
				row1 = i;
				col1 = j;
			}
			if (matrix[i][j] == pt[1])
			{
				row2 = i;
				col2 = j;
			}
		}
	}
	for (i = 0; i < 2; i++)
	{

		if (row1 == row2)
		{
			if (col2 == 4)
			{
				cout << matrix[row1][col1 + 1] << matrix[row2][0];
			}
			else
			{
				cout << matrix[row1][col1 + 1] << matrix[row2][col2 + 1];
			}
		}
		if (col1 == col2)
		{
			if (row2 == 4)
			{
				cout << matrix[row1 + 1][col1] << matrix[0][col2];
			}
			else
			{
				cout << matrix[row1 + 1][col1] << matrix[row2 + 1][col2];
			}
		}
		if (row1 != row2 && col1 != col2)
		{
			cout << matrix[row1][col2] << matrix[row2][col1];
		}
	}
	return 0;
}