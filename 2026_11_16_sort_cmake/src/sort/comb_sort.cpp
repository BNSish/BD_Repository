#include "comb_sort.hpp"
#include <utility>

void combSort(int* arr, const int len) {
	int gap = len - 1;
	bool isSwapped = true;
	while (gap > 1 || isSwapped) {
		isSwapped = false;
		for (int i = 0; i + gap < len; ++i) {
			if (arr[i] > arr[i + gap]) {
				std::swap(arr[i], arr[i + gap]);
				isSwapped = true;
			}
		}
		if (gap > 1) {
			constexpr double factor = 1.3;
			gap = gap / factor;
		}
	}
}