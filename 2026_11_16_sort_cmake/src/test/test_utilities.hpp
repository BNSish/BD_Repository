#pragma once

#include "test_utilities.hpp"

#include <gtest/gtest.h>

#include <algorithm>

void checkSort(void (*sort)(int*, int), int* actual, const int len) {
	const auto expected = new int[len];
	std::copy_n(actual, len, expected);

	std::sort(expected, expected + len);
	sort(actual, len);

	for (int i = 0; i < len; ++i) {
		ASSERT_EQ(expected[i], actual[i])
			<< "Массив ожидаемый и отсортированный отличаются в элементе с индексом "
			<< i << ": "
			<< "есть " << actual[i]
			<< ", а должен быть " << expected[i];
	}

	delete[] actual;
	delete[] expected;
}