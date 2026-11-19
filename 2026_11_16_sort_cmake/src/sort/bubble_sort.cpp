#include "bubble_sort.hpp"
#include <utility>

void bubbleSortClassic(int* arr, const int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void bubbleSortNoSwaped(int* arr, const int len) {
	bool isSwapped;
	int i = 0;
	do {
		isSwapped = false;
		for (int j = 0; j < len - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}
		++i;
	} while (isSwapped);
}

void bubbleSortOptimized(int* arr, const int len) {
	int right = len - 1;
	while (right > 0) {
		int lastSwap = 0;
		for (int i = 0; i < right; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				lastSwap = i + 1;
			}
		}
		right = lastSwap;
	}
}