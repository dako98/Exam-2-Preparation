//
//// C++ program for implementation of Heap Sort 
//#include <iostream> 
//using namespace std;
//
//// To heapify a subtree rooted with node i which is 
//// an index in arr[]. n is size of heap 
//void heapify(int arr[], int n, int i)
//{
//	int smallest = i; // Initialize smalles as root 
//	int l = 2 * i + 1; // left = 2*i + 1 
//	int r = 2 * i + 2; // right = 2*i + 2 
//
//	// If left child is smaller than root 
//	if (l < n && arr[l] < arr[smallest])
//		smallest = l;
//
//	// If right child is smaller than smallest so far 
//	if (r < n && arr[r] < arr[smallest])
//		smallest = r;
//
//	// If smallest is not root 
//	if (smallest != i) {
//		swap(arr[i], arr[smallest]);
//
//		// Recursively heapify the affected sub-tree 
//		heapify(arr, n, smallest);
//	}
//}
//
//// main function to do heap sort 
//void heapSort(int arr[], int n)
//{
//	// Build heap (rearrange array) 
//	for (int i = n / 2 - 1; i >= 0; i--)
//		heapify(arr, n, i);
//
//	// One by one extract an element from heap 
//	for (int i = n - 1; i >= 0; i--) {
//		// Move current root to end 
//		swap(arr[0], arr[i]);
//
//		// call max heapify on the reduced heap 
//		heapify(arr, i, 0);
//	}
//}
//
///* A utility function to print array of size n */
//void printArray(int arr[], int n)
//{
//	for (int i = 0; i < n; ++i)
//		cout << arr[i] << " ";
//	cout << "\n";
//}
//
//// Driver program 
//int main()
//{
//	int arr[] = { 4, 6, 3, 2, 9 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	heapSort(arr, n);
//
//	cout << "Sorted array is \n";
//	printArray(arr, n);
//}


#include <iostream>

//-----------MY_IMPLEMENTATION--------------------

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
	for (int i = size/2-1; i >= 0 ; --i)
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


int main()
{
	const int size = 10;
	int arr[size] = { 8,7,9,10,3,4,1,12,6,5 };

	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';

	myHeapSort(arr, 10);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}

	return 0;
}