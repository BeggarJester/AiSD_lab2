#include "AiSD_lab2_Sort_and_Search.h"

void main() {
	const int size_array = 10;

	cout << "Generate an array with " << size_array << " elements:\n";
	int* QuickTest_array = new int[size_array];
	int first = 0; int last = size_array - 1;
	srand(time(NULL)); // clear the random element 
	for (int i = 0; i < size_array; i++)
	{
		QuickTest_array[i] = rand() % 1000;
	}
	for (int i = 0; i < size_array; i++) {
		cout << QuickTest_array[i] << ' ';
	}
	cout << "\nSort the array by QuickSort:\n";
	QuickSort(QuickTest_array, first, last);
	for (int i = 0; i < size_array; i++) {
		cout << QuickTest_array[i] << ' ';
	}
	delete[]QuickTest_array;

	cout << "\n\n";

	cout << "Generate an array with " << size_array << " elements:\n";
	int* BubbleTest_array = new int[size_array];
	for (int i = 0; i < size_array; i++)
	{
		BubbleTest_array[i] = rand() % 1000;
	}
	for (int i = 0; i < size_array; i++) {
		cout << BubbleTest_array[i] << ' ';
	}
	cout << "\nSort the array by BubbleSort:\n";
	BubbleSort(BubbleTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << BubbleTest_array[i] << ' ';
	}
	delete[]BubbleTest_array;

	cout << "\n\n";

	cout << "Generate an array with " << size_array << " elements:\n";
	int* BogoTest_array = new int[size_array];
	for (int i = 0; i < size_array; i++)
	{
		BogoTest_array[i] = rand() % 1000;
	}
	for (int i = 0; i < size_array; i++) {
		cout << BogoTest_array[i] << ' ';
	}
	cout << "\nSort the array by BogoSort:\n";
	BogoSort(BogoTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << BogoTest_array[i] << ' ';
	}
	delete[]BogoTest_array;

	cout << "\n\n";

	cout << "Generate an array with " << size_array << " elements:\n";
	char* CountingTest_array = new char[size_array];
	for (int i = 0; i < size_array; i++)
	{
		CountingTest_array[i] = rand() % 255;
	}
	for (int i = 0; i < size_array; i++) {
		cout << CountingTest_array[i] << ' ';
	}
	cout << "\nSort the array by CountingSort:\n";
	CountingSort(CountingTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << CountingTest_array[i] << ' ';
	}
	delete[]CountingTest_array;

	cout << "\n\n";

	cout << "Generate an array with " << size_array << " elements:\n";
	int* BinarySearchTest_array = new int[size_array];
	for (int i = 0; i < size_array; i++)
	{
		BinarySearchTest_array[i] = 20 - i;
	}
	for (int i = 0; i < size_array; i++) {
		cout << BinarySearchTest_array[i] << " ";
	}
	cout << "\nSort the array by BubbleSort:\n";
	BubbleSort(BinarySearchTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << BinarySearchTest_array[i] << ' ';
	}

	cout << "\nGet the index of '7':\n";
	try {
		cout << BinarySearch(BinarySearchTest_array, size_array, 7);
	}
	catch (const invalid_argument error) {
		cout << error.what();
	}
	cout << "\nGet the index of '17':\n";
	cout << "The index of '17' is ";
	try {
		cout << BinarySearch(BinarySearchTest_array, size_array, 17);
	}
	catch (const invalid_argument error) {
		cout << error.what();
	}

	delete[]BinarySearchTest_array;

	cout << "\n\nComparison QuickSort and BubbleSort:\n\n";

	// Examples of QuickSort work for comparison with BubbleSort
	for (int degree = 1; degree < 6; degree++) {
		int size = pow(10, degree);
		int* array = new int[size];
		int first = 0; int last = size - 1;
		long double elapsed_secs = 0;
		for (int i = 0; i < 10; i++) {
			srand(time(NULL)); // clear the random element list of rand()
			for (int i = 0; i < size; i++) array[i] = rand() % 1000;
			clock_t begin = clock();
			QuickSort(array, first, last);
			clock_t end = clock();
			elapsed_secs += long double(end - begin) / CLOCKS_PER_SEC;
		}
		elapsed_secs /= 10;
		cout << "QuickSort of " << size << " element array required " << elapsed_secs << " seconds\n";
		delete[]array;

	}

	cout << "\n";

	// Examples of BubbleSort work for comparison with QuickSort
	for (int degree = 1; degree < 6; degree++) {
		int size = pow(10, degree);
		int* array = new int[size];
		int first = 0; int last = size - 1;
		long double elapsed_secs = 0;
		for (int i = 0; i < 10; i++) {
			srand(time(NULL)); // clear the random element list of rand()
			for (int i = 0; i < size; i++) array[i] = rand() % 1000;
			clock_t begin = clock();
			BubbleSort(array, size);
			clock_t end = clock();
			elapsed_secs += long double(end - begin) / CLOCKS_PER_SEC;
		}
		elapsed_secs /= 10;
		cout << "BubbleSort of " << size << " element array required " << elapsed_secs << " seconds\n";
		delete[]array;
	}

}