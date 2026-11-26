#include "heap_sort.hpp"
#include <utility>

static void heapify(int* arr, int len, int currentRoot);

void heapSort(int* arr, const int len) {
	for (int i = len / 2 - 1; i>= 0; --i) {
		heapify(arr, len, i);
	}

	for (int i = len - 1; i >= 0; --i) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

static void heapify(int* arr, const int len, const int currentRoot) {
	int max = currentRoot;
	const int left = 2 * currentRoot + 1;
	const int right = 2 * currentRoot + 2;

	if (left < len && arr[left] > arr[max]) {
		max = left;
	}
	if (right < len && arr[right] > arr[max]) {
		max = right;
	}
	if (max != currentRoot) {
		std::swap(arr[currentRoot], arr[max]);
		heapify(arr, len, max);
	}
}