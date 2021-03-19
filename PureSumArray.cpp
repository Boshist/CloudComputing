#include <iostream>

int PureSumArray(int *Array, int start, int end);

int main()
{

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	std::cout << PureSumArray(arr, 0, 8);
	return 0;
}

int PureSumArray(int *Array, int start, int end) {

	if (start < end)
		return Array[start] + PureSumArray(Array, start + 1, end);
	
	return 0;
}