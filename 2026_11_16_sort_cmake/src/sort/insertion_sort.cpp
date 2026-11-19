#include "insertion_sort.hpp"

void insertionSort(int* arr, const int len) {
	for (int i = 1; i < len; ++i) {
		int j = i;
		const int x = arr[j];
		while (j > 0 && x < arr[j - 1]) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = x;
	}
}