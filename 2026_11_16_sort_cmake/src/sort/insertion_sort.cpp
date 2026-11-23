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

void insertionSortBinarySearch(int* arr, const int len) {
	for (int i = 1; i < len; ++i) {
		const int x = arr[i];

		int right = 0;
		int left = i - 1;
		while (right < left) {
			const int mid = right + (left - right) / 2;
			if (x < arr[mid]) {
				left = mid;
			}
			else {
				right = mid + 1;
			}
		}

		if (x < arr[right]) {
			for (int j = i; j > right; --j) {
				arr[j] = arr[j - 1];
			}
			arr[right] = x;
		}
	}
}