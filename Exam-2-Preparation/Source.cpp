#include <iostream>
#include "HashTable.h"
#include "HeapSort.h"


int main()
{

//	HashTable test;
//
//	test.Add(0);
//	test.Add(1);
//	test.Add(2);
//	test.Add(3);
//	test.Add(4);
//	test.Add(5);
//	test.Add(6);
//	test.Add(7);
//	test.Add(8);
//	test.Add(9);
//	test.Add(10);
//
//	test.Remove(15);
//
//	test.Find(3) = 11;
//
//	test.Debug_PrintChains();


	int arr[10] = { 1,5,2,7,3,8,6,0,9,4 };
	heapSort(arr, 10);

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}