#include <iostream>
using namespace std;

bool importData(int** pArr,int szRow,int szCol);
void printMatrix(int** pArr,int szRow,int szCol);
int** addMatrix(int** pArr1,int **pArr2,int szRow,int szCol);
void freeMem(int** pArr,int szRow,int szCol);

bool importData(int** pArr, int szRow, int szCol)
{
	if (pArr)
	{
		for (int i = 0; i < szRow; i++)
			for (int j = 0; j < szCol; j++)
			{
				cout << "\nA[" << i + 1 << "]" << "[" << j + 1 << "] = ";
				cin >> pArr[i][j];
			}
		return true;
	}
	return false;
}

int** add2Matrix(int** pArr1, int** pArr2, int szRow, int szCol)
{
	for (int i = 0; i < szRow; i++)
	{
		for (int j = 0; j < szCol; j++)
		{
			pArr1[i][j] = pArr1[i][j] + pArr2[i][j];
		}
	}
	return pArr1;	
}

void printMatrix(int** pArr, int szRow, int szCol)
{
	cout << "Matrix Sum[" << szRow << "][" << szCol << "]: \n";
	for (int i = 0; i < szRow; i++)
	{
		for (int j = 0; j < szCol; j++)
		{
			cout << pArr[i][j] << " ";
		}
		cout << "\n";
	}
}

void freeMem(int** pArr, int szRow, int szCol)
{
	for (int i = 0; i < szRow; i++)
		delete[] pArr[i];

	delete[] pArr;
}

int main()
{
	int** pArr1, ** pArr2;
	int a, b;

	cout << "Please input Matrix size axb: \n";
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
		
	pArr1 = new int* [a];
	for (int i = 0; i < a; i++)
	{
		pArr1[i] = new int[b];
	}

	cout << "\nInput value of Matrix 1:\n";
	importData(pArr1, a, b);

	pArr2 = new int* [a];
	for (int i = 0; i < a; i++)
	{
		pArr2[i] = new int[b];
	}

	cout << "\nInput value of Matrix 2:\n";
	importData(pArr2, a, b);

	add2Matrix(pArr1, pArr2, a, b);
	cout << "Sum of 2 Matrix:\n";
	printMatrix(pArr1, a, b);

	freeMem(pArr1, a, b);
	freeMem(pArr2, a, b);
	
	return 0;
}