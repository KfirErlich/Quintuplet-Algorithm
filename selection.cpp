void swap(double* a, double* b)
{
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(double* arr, int left, int right)
{
	double pivot = arr[left];

	while (left != right)
	{
		if (arr[left] == pivot)
		{
			if (pivot > arr[right])
			{
				swap(&arr[left], &arr[right]);
				left++;
			}
			else
				right--;
		}
		else
		{
			if (pivot > arr[left])
				left++;
			else {
				swap(&arr[right], &arr[left]);
				right--;
			}
		}
	}
	return left;//left and right are both the center
}
double selection(double arr[], int left, int right, int i)
{
	int pivot;
	int leftPart;

	pivot = partition(arr, left, right);
	leftPart = pivot - left + 1;

	if (i == leftPart)
		return arr[pivot];
	if (i < leftPart)
		return selection(arr, left, pivot - 1, i);
	else
		return selection(arr, pivot + 1, right, i - leftPart);
}