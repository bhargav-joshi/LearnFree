// C++ implementation of Shell Sort
#include <iostream>

/* function to sort arr using shellSort */
void shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2) {
	
		for (int i = gap; i < n; i += 1) {
		
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

int main()
{
	int arr[] = { 12, 34, 54, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Array before sorting: \n";
	printArray(arr, n);

	shellSort(arr, n);

	std::cout << "Array after sorting: \n";
	printArray(arr, n);
}
