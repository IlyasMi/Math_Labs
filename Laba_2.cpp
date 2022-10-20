#include<iostream>
using namespace std;

bool result_matrix[7];

int matrix[5][5] =
{
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1}
};

void checkReflect()
{
	bool matchFirst = false;
	for (int i = 0; i < 5; i++)
	{

		if (matrix[i][i] == 1)
		{
			matchFirst = true;

		}
		else
		{
			matchFirst = false;
			break;
		}

	}
	result_matrix[1] = matchFirst;


}

void checkUnReflect()
{
	bool matchFirst = false;
	for (int i = 0; i < 5; i++)
	{

		if (matrix[i][i] == 0)
		{
			matchFirst = true;

		}
		else
		{
			matchFirst = false;
			break;
		}

	}
	result_matrix[2] = matchFirst;


}

void Symmetry()
{
	bool matchFirst = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			if (i != 4 && matrix[i][j] != matrix[j][i])
			{
				matchFirst = 1;

			}

		}
	}
	if (matchFirst == true && result_matrix[1]==true)
	{
		result_matrix[3] = true;
		result_matrix[4] = false;
		

	}
	else
	{
		result_matrix[3] = false;
		result_matrix[4] = true;
	}
}

void aSymmetry()
{
	bool matchFirst = false;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i != j)
			{

				if (matrix[i][j] != matrix[j][i])
				{
					matchFirst = 1;

				}
				else if (matrix[i][j] == matrix[j][i])
				{
					matchFirst = 0;
					i = 5; j = 5;

				}
			}

		}
	}
	result_matrix[6] = matchFirst;
}

void transitivity()
{
	
	bool matchFirst, matchSecond = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matchFirst = false;
			for (int k = 0; k < 5; k++)
			{
				matchFirst = matrix[i, k] && matrix[k, j] || matchFirst;
			}
				
			if (matchSecond = matchFirst && !matrix[i, j])
			{
				break;
			}
		}
		if (matchSecond) break;
	}
	result_matrix[5] = matchFirst;
}

void connectivity()
{
	bool matchFirst = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i != j && matrix[i][j] != 0)
			{
				matchFirst = false;
				break;
			}
		}
	}
	if (result_matrix[0] = true&&((matrix[0][0]==1&&matrix[0][1]==1) or(matrix[0][0]==0 && matrix[0][1]==0)))
	{
			result_matrix[7] = matchFirst;
	}
	
}

int main()
{
	setlocale(LC_ALL, "rus");

	checkReflect();
	cout << "Рефлексивность - " << result_matrix[1] << endl;
	checkUnReflect();
	cout << "Антирефлексивность - " << result_matrix[2] << endl;
	Symmetry();
	cout << "Симметричность - " << result_matrix[3] << endl;
	cout << "Антисимметричность - " << result_matrix[4] << endl;
	transitivity();
	cout << "Транзитивность - " << result_matrix[5] << endl;
	aSymmetry();
	cout << "Асимметричность - " << result_matrix[6] << endl;
	connectivity();
	cout << "Связность - " << result_matrix[7] << endl;
	return 0;
}