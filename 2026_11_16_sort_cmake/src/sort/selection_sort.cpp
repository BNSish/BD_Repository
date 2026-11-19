#include "selection_sort.hpp"

#include <utility>

void selectionSort(int* arr, const int len) {
	for (int i = 0; i < len - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < len; ++j) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			std::swap(arr[i], arr[min]);
		}
	}
}
