#include "shell_sort.hpp"

void shellSort(int* arr, const int len) {
	int gap = len / 2;
	while (gap > 0) {
		for (int i = gap; i < len; ++i) {
			int j = i;
			const int x = arr[j];
			while (j >= gap && x < arr[j - gap]) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = x;
		}
		gap /= 2;
	}
}