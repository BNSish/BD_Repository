foreach (
        name
        test_bubble_sort_classic
        test_bubble_sort_no_swapped_opt
        test_bubble_sort_optimized
        test_shaker_sort_classic
        test_shaker_sort_optimized
        test_odd_even_sort
        test_comb_sort
        test_selection_sort
        test_insertion_sort
        test_insertion_sort_binary_search
        test_shell_sort
        test_heap_sort
        test_quick_sort
        test_merge_sort
)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} PRIVATE gtest sortlib)
    add_test(NAME ${name} COMMAND ${name})
endforeach ()