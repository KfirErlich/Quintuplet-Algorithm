#include "functionsSigns.h"

void bubbleSort(double* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}

}

double Quintuplet(double* arr, int n, int idx)
{
	int divider = 0, j = 0;
	int arrLeftOver = n % 5;
	int length = (n % 5 == 0) ? (n / 5) : ((n / 5) + 1);

	if (n <= 5)
	{
		bubbleSort(arr, n);
		return arr[idx - 1];
	}
	else
	{
		double* B = new double[length];
		while (divider < n && (n - divider) / 5 != 0)
		{
			bubbleSort(arr + divider, 5);
			int median = divider + 2;
			B[divider / 5] = arr[median];
			divider += 5;
		}
		if (arrLeftOver)
		{
			bubbleSort(arr + divider, arrLeftOver);
			int median = (arrLeftOver < 3) ? (divider) : (divider + 1);
			B[length - 1] = arr[median];
		}

		int left = 0, right = length - 1;
		double pivot = selection(B, left, right, ((length + 1) / 2));

		while (arr[j] != pivot)
			j++;

		swap(&arr[j], &arr[0]);

		int pivotIdx = partition(arr, 0, n - 1);

		if (pivotIdx == idx - 1)
		{
			delete[]B;
			return arr[idx - 1];
		}
		else if (pivotIdx > idx - 1)
		{
			delete[]B;
			return Quintuplet(arr, pivotIdx, idx);
		}
		else
		{
			delete[]B;
			return Quintuplet(arr + pivotIdx + 1, n - (pivotIdx + 1), idx - (pivotIdx + 1));
		}
	}
}