#include "merge_sort.hpp"

static void merge(int* arr, int* buf, int left, int mid, int right);

void mergeSort(int* arr, int* buf, const int left, const int right) {
	if (right - left <= 1) {
		return;
	}
	const int mid = left + (right - left) / 2;

	mergeSort(arr, buf, left, mid);
	mergeSort(arr, buf, mid, right);

	merge(arr, buf, left, mid, right);
}

static void merge(int* arr, int* buf, const int left, const int mid, const int right) {
	int i = left;
	int j = mid;
	int k = left;

	while (i < mid && j < right) {
		if (arr[i] <= arr[j]) {
			buf[k++] = arr[i++];
		}
		else {
			buf[k++] = arr[j++];
		}
	}

	while (i < mid) {
		buf[k++] = arr[i++];
	}
	while (j < right) {
		buf[k++] = arr[j++];
	}

	for (i = left; i < right; ++i) {
		arr[i] = buf[i];
	}
}
