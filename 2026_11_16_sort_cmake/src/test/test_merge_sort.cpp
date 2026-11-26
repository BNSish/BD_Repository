#include "merge_sort.hpp"
#include <gtest/gtest.h>
#include "test_utilities.hpp"

TEST(MergeSort, without_equal_elements) {
	checkSort(mergeSort, new int[]{1, 8, 2, 5, 3, 11}, 6);
}

TEST(MergeSort, with_equal_elements) {
	checkSort(mergeSort, new int[]{5, 1, 5, 2, 1, 2, 5}, 7);
}

TEST(MergeSort, reversed) {
	checkSort(mergeSort, new int[]{9, 7, 5, 3, 2, 1}, 6);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}