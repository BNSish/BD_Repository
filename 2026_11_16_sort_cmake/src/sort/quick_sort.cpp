#include "quick_sort.hpp"
#include <utility>

void quickSort(int* arr, const int left, const int right) {
	if (right - left <= 1) {
		return;
	}

	const int pivot = arr[left + (right - left) / 2];
	int i = left;
	int j = right - 1;

	while (i <= j) {
		while (arr[i] < pivot) {
			++i;
		}
		while (arr[j] > pivot) {
			--j;
		}
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}

	quickSort(arr, left, j + 1);
	quickSort(arr, i, right);
}