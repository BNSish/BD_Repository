#include <algorithm>
#include <iostream>
#include <chrono>
#include <format>
#include <cstdlib>

#include "bubble_sort.hpp"
#include "shaker_sort.hpp"
#include "odd_even_sort.hpp"
#include "comb_sort.hpp"
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
#include "shell_sort.hpp"

static bool isSorted(const int* arr, const int len) {
	for (int i = 0; i < len - 1; ++i) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

static void checkSpeed(const char* name, void (*sort)(int*, int), const int* arr, const int len) {
	const auto copy = new int[len];
	std::copy_n(arr, len, copy);

	const auto start = std::chrono::steady_clock::now();
	sort(copy, len);
	const auto end = std::chrono::steady_clock::now();
	const std::chrono::duration<double, std::milli> time = end - start;

	if (!isSorted(copy, len)) {
		std::cout << "ERROR: сортировка " << name << " не прошла тест!" << std::endl;
	}
	else {
		std::cout << std::format("| {:^50} | {:^6} | {:^8.2f} |", name, len, time.count()) << std::endl;
	}

	delete[] copy;
}

static void generateArray(int* arr, const int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] = rand();
	}
}

static void run(const int* arr, const int len) {
	checkSpeed("Сортировка пузырьком (классическая)", bubbleSortClassic, arr, len);
	checkSpeed("Сортировка пузырьком (выход при отсутствии обмена)", bubbleSortNoSwaped, arr, len);
	checkSpeed("Сортировка пузырьком (оптимизация правой границы)", bubbleSortOptimized, arr, len);

	checkSpeed("Сортировка шейкером (классическая)", shakerSortClassic, arr, len);
	checkSpeed("Сортировка шейкером (оптимизация правой границы)", shakerSortOptimized, arr, len);

	checkSpeed("Чётная-нечётная сортировка", oddEvenSort, arr, len);

	checkSpeed("Сортировка расчёской", combSort, arr, len);

	checkSpeed("Сортировка выборкой", selectionSort, arr, len);

	checkSpeed("Сортировка вставками", insertionSort, arr, len);

	checkSpeed("Сортировка Шелла", shellSort, arr, len);
}

int main() {
	constexpr int arrayLength = 10000;
	constexpr int bigArrayLength = 100000;

	int arr[arrayLength];
	int bigArr[bigArrayLength];

	generateArray(arr, arrayLength);
	generateArray(bigArr, bigArrayLength);

	run(arr, arrayLength);
	run(bigArr, bigArrayLength);
}