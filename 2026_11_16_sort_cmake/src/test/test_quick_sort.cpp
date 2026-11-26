#include "quick_sort.hpp"
#include <gtest/gtest.h>
#include "test_utilities.hpp"

TEST(QuickSort, without_equal_elements) {
	checkSort(quickSort, new int[]{1, 8, 2, 5, 3, 11}, 6);
}

TEST(QuickSort, with_equal_elements) {
	checkSort(quickSort, new int[]{5, 1, 5, 2, 1, 2, 5}, 7);
}

TEST(QuickSort, reversed) {
	checkSort(quickSort, new int[]{9, 7, 5, 3, 2, 1}, 6);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}