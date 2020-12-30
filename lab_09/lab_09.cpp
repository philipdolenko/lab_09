// lab_09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <limits>

using namespace std;

//21.	Дана квадратная матрица A порядка n.Получить матрицу AB,
// а также номер строки и столбца, на пересечении которых находится
// элемент с наименьшим значением.Элементы матрицы B вычисляются 
// по формуле : Bij = 1 / (i + j-1)

const int MAX_SIZE = 50;

void loopTask(void(*task)(void)) {
	char userInput;

	do {
		task();
		cout << "Enter 'y' to continue any other kay to exit.\n";
		cin >> userInput;
	} while (userInput == 'y' || userInput == 'Y');
}

void printMatrix(int c, int r, float ** mrx) {
	for (int i = 0; i < r; i++)
	{
		cout << "  " << endl;
		for (int j = 0; j < c; j++)
		{
			cout << "  " << mrx[i][j];
		}
	}
	cout << endl;
}


void fillMatrix(int size, float ** matrix) {
	cout << "Enter matrix elements " << endl;
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new float[MAX_SIZE];
		for (int j = 0; j < size; j++)
		{
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
}

void calculateMatrixB(int size, float **matrix) {
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new float[MAX_SIZE];
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = 1 / ((i + 1) + (j + 1) - 1.);
		}
	}
}

void multiplyMatrixs(
	int size,
	float **res,
	float **first,
	float **sec
) {
	for (int i = 0; i < size; i++)
	{
		res[i] = new float[MAX_SIZE];
		for (int j = 0; j < size; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < size; k++) {
				res[i][j] += first[i][k] * sec[k][j];
			}
		}
	}
}

void findMinimum(
	int size,
	float **matrix, 
	int (*minI),
	int (*minJ),
	float (*min)
) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] < *min) {
				*min = matrix[i][j];
				*minI = i;
				*minJ = j;
			}
		}
	}
}

void lab() {
	int matrixSize, minI, minJ;
	float ** A = new float*[MAX_SIZE];
	float ** B = new float*[MAX_SIZE];
	float ** AB = new float*[MAX_SIZE];

	float min = numeric_limits<float>::max();

	cout << "Enter the size of the matrix ";
	cin >> matrixSize;
	
	fillMatrix(matrixSize, A);

	cout << "\nMatrix A: " << endl;
	printMatrix(matrixSize, matrixSize, A);

	calculateMatrixB(matrixSize, B);

	cout << "\nMatrix B: " << endl;
	printMatrix(matrixSize, matrixSize, B);

	multiplyMatrixs(matrixSize, AB, A, B);

	cout << "\nMatrix AB: " << endl;
	printMatrix(matrixSize, matrixSize, AB);

	findMinimum(matrixSize, AB, &minI, &minJ, &min);
	cout << "\nMin element = " << min << "; row = " << minI << "; column = " << minJ << "; " << endl;
}

int main()
{
	loopTask(lab);
}