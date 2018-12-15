#ifndef _HEAP_SORT_RECURSIVE_
#define _HEAP_SORT_RECURSIVE_

#include <iostream>

void myHeapify(int arr[], int size, int root_index)
{
	//making min heap

	int left_child_index = root_index * 2 + 1;
	int right_child_index = root_index * 2 + 2;
	int minimal_index = root_index;

	if (left_child_index < size && arr[left_child_index] < arr[minimal_index])
		minimal_index = left_child_index;

	if (right_child_index < size && arr[right_child_index] < arr[minimal_index])
		minimal_index = right_child_index;

	if (minimal_index != root_index)
	{
		std::swap(arr[minimal_index], arr[root_index]);

		myHeapify(arr, size, minimal_index);
	}
}


void initialHeapification(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		myHeapify(arr, size, i);
	}
}

void _myHeapSort(int arr[], int size);


void myHeapSort(int arr[], int size)
{
	initialHeapification(arr, size);
	//now the array is a heap

	_myHeapSort(arr, size);
}

void _myHeapSort(int arr[], int size)
{//After the array has been made to a heap
	if (size == 0)
		return;

	std::swap(arr[0], arr[size - 1]);
	myHeapify(arr, size - 1, 0);
	_myHeapSort(arr, size - 1);
}


#endif // !_HEAD_SORT_RECURSIVE_
