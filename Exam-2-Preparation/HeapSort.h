#ifndef _HEAP_SORT_
#define _HEAP_SORT_

#include <iostream>

void heapify(int* &arr, int size, int root_index);


void heapSort(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		heapify(arr, size, i);
	}

	for (int i = size - 1; i > 0; --i)
	{
		std::swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

void heapify(int* &arr, int size, int root_index)
{
	int left_index = root_index * 2 + 1;
	int right_index = root_index * 2 + 2;
	int minimal_index = root_index;

	if (left_index<size && arr[left_index]<arr[minimal_index])
	{
		minimal_index = left_index;
	}

	if (right_index < size && arr[right_index] < arr[minimal_index])
	{
		minimal_index = right_index;
	}

	if (minimal_index!=root_index)
	{
		std::swap(arr[minimal_index], arr[root_index]);

		heapify(arr, size, minimal_index);
	}

}



#endif // !_HEAP_SORT_
