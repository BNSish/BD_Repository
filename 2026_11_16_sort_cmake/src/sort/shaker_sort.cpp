#include "shaker_sort.hpp"
#include <utility>

void shakerSortClassic(int* arr, const int len) {
	bool isSwapped;
	int right = len - 1;
	int left = 0;
	do {
		isSwapped = false;
		for (int i = left; i < right; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped) {
			break;
		}
		--right;
		for (int i = right; i > left; --i) {
			if (arr[i] < arr[i - 1]) {
				std::swap(arr[i], arr[i - 1]);
				isSwapped = true;
			}
		}
		++left;
	} while (isSwapped);
}

void shakerSortOptimized(int* arr, int len) {
	bool isSwapped = true;
	int right = len - 1;
	int left = 0;

	while (isSwapped && left < right) {
		isSwapped = false;
		int lastSwap = left;
		for (int i = left; i < right; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				isSwapped = true;
				lastSwap = i;
			}
		}
		right = lastSwap;

		if (!isSwapped) {
			break;
		}


		lastSwap = right;
		for (int i = right; i > left; --i) {
			if (arr[i] < arr[i - 1]) {
				std::swap(arr[i], arr[i - 1]);
				isSwapped = true;
				lastSwap = i;
			}
		}
		left = lastSwap;
	}
}
