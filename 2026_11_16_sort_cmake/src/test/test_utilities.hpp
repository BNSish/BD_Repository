#pragma once

#include <gtest/gtest.h>

#include <algorithm>

inline int* makeSortedCopy(const int* actual, const int len) {
	const auto expected = new int[len];
	std::copy_n(actual, len, expected);
	std::sort(expected, expected + len);
	return expected;
}

inline void assertSorted(const int* actual, const int* expected, const int len) {
	for (int i = 0; i < len; ++i) {
		ASSERT_EQ(expected[i], actual[i])
			<< "Массив ожидаемый и отсортированный отличаются в элементе с индексом "
			<< i << ": "
			<< "есть " << actual[i]
			<< ", а должен быть " << expected[i];
	}
}

inline void checkSort(void (*sort)(int*, int), int* actual, const int len) {
	const int* expected = makeSortedCopy(actual, len);

	sort(actual, len);

	assertSorted(actual, expected, len);

	delete[] actual;
	delete[] expected;
}

inline void checkSort(void (*sort)(int*, int, int), int* actual, const int len) {
	const int* expected = makeSortedCopy(actual, len);

	sort(actual, 0, len);

	assertSorted(actual, expected, len);

	delete[] actual;
	delete[] expected;
}

inline void checkSort(void (*sort)(int*, int*, int, int), int* actual, const int len) {
	const int* expected = makeSortedCopy(actual, len);
	const auto buf = new int[len];

	sort(actual, buf, 0, len);

	delete[] buf;
	assertSorted(actual, expected, len);

	delete[] actual;
	delete[] expected;
}