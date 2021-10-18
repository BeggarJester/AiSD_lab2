#pragma once
#include <iostream>
#include <ctime>

using namespace std;

// declaration the constant
const int size = 10;

// quick sort in ascending order
void QuickSort(int* array, int first, int last) {
	int middle;
	int left = first, right = last;
	middle = array[(left + right) / 2]; //  calculate the support element
	do
	{
		while (array[left] < middle) left++;
		while (array[right] > middle) right--;
		if (left <= right) // swap the elements
		{
			int temporary = array[left];
			array[left] = array[right];
			array[right] = temporary;
			left++;
			right--;
		}
	} while (left < right);
	if (first < right) QuickSort(array, first, right); // sort the sub-array
	if (left < last) QuickSort(array, left, last);
}

// bubble sort in ascending order
void BubbleSort(int* array, const int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (array[j] > array[j + 1]) {
				int temporary = array[j]; // create a temporary element
				array[j] = array[j + 1]; // to swap the lements
				array[j + 1] = temporary;
			}
		}
	}
}

// check the correct array order for bogo sort
int ArrayCorrect(int* array, int size) {
	while (size-- > 0)
		if (array[size - 1] > array[size])
			return 0;
	return 1;
}

// swap the array random elements for bogo sort
void BogoShuffle(int* array, int size) {
	for (int i = 0; i < size; ++i)
		swap(array[i], array[(rand() % size)]);
}

// bogo sort in ascending order
void BogoSort(int* array, int size) {
	while (!ArrayCorrect(array, size)) // while array is not sorted in ascending order
		BogoShuffle(array, size); // swap the array random elements
}

// counting sort in lexicographic order
void CountingSort(char* array, int size) {
	char char_array[256] = { 0 }; // 256 is the max different count of char
	for (int i = 0; i < size; ++i) {
		++char_array[array[i]]; // calculate the count of each char
	}

	int order = 0; // go through all char
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < char_array[i]; ++j) {
			array[order++] = i;
		}
	}
}

// binary search the element in array
int BinarySearch(int* array, int size, int looking_for) {
	if (ArrayCorrect(array, size) == 1) { // if array is sorted in ascending order
		int left = 0;
		int right = size - 1;
		bool IsFound = false;
		int middle;

		while ((left <= right) && (IsFound != true)) {
			middle = (left + right) / 2; // calculate the middle index

			if (array[middle] == looking_for) IsFound = true; // if moddle index is looking for element
			if (array[middle] > looking_for) right = middle - 1; // discard the useless part of array
			else left = middle + 1;
		}

		if (IsFound) return middle; // if looking for element is exist
		else
		{
			throw invalid_argument("There is not element in array");
		}
	}
	else throw invalid_argument("The array is not sorted in ascending order");
}
