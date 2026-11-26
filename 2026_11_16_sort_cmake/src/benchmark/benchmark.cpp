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
#include "heap_sort.hpp"
#include "quick_sort.hpp"
#include "merge_sort.hpp"

static bool isSorted(const int* arr, const int len) {
	for (int i = 0; i < len - 1; ++i) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

static void reportResult(const char* name, const int* arr, const int len, const std::chrono::duration<double> sec) {
	if (!isSorted(arr, len)) {
		std::cout << "ERROR: сортировка " << name << " не прошла тест!" << std::endl;
	}
	else {
		std::cout << std::format("| {:^52} | {:^6} | {:^8.4f} |", name, len, sec.count()) << std::endl;
	}
}

static void checkSpeed(const char* name, void (*sort)(int*, int), const int* arr, const int len) {
	const auto copy = new int[len];
	std::copy_n(arr, len, copy);
	const auto start = std::chrono::high_resolution_clock::now();
	sort(copy, len);
	const auto end = std::chrono::high_resolution_clock::now();
	reportResult(name, copy, len, end - start);
	delete[] copy;
}

static void checkSpeed(const char* name, void (*sort)(int*, int, int), const int* arr, const int len) {
	const auto copy = new int[len];
	std::copy_n(arr, len, copy);
	const auto start = std::chrono::high_resolution_clock::now();
	sort(copy, 0, len);
	const auto end = std::chrono::high_resolution_clock::now();
	reportResult(name, copy, len, end - start);
	delete[] copy;
}

static void checkSpeed(const char* name, void (*sort)(int*, int*, int, int), const int* arr, const int len) {
	const auto copy = new int[len];
	std::copy_n(arr, len, copy);
	const auto start = std::chrono::high_resolution_clock::now();
	const auto buf = new int[len];
	sort(copy, buf, 0, len);
	delete[] buf;
	const auto end = std::chrono::high_resolution_clock::now();
	reportResult(name, copy, len, end - start);
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

	checkSpeed("Сортировка вставками (классическая)", insertionSort, arr, len);
	checkSpeed("Сортировка вставками (оптимизация бинарным поиском)", insertionSortBinarySearch, arr, len);

	checkSpeed("Сортировка Шелла", shellSort, arr, len);

	checkSpeed("Пирамидальная сортировка", heapSort, arr, len);

	checkSpeed("Быстрая сортировка", quickSort, arr, len);

	checkSpeed("Сортировка слиянием", mergeSort, arr, len);
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