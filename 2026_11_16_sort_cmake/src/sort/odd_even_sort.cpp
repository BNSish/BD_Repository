#include "odd_even_sort.hpp"

#include <utility>

void oddEvenSort(int* arr, const int len) {
	bool isSwappedEven = true;
	bool isSwappedOdd = true;
	while (isSwappedEven || isSwappedOdd) {
		isSwappedEven = false;
		isSwappedOdd = false;

		for (int i = 0; i < len - 1; i += 2) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				isSwappedEven = true;
			}
		}

		for (int i = 1; i < len - 1; i += 2) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				isSwappedOdd = true;
			}
		}
	}
}
