add_library(sortlib SHARED
        bubble_sort.cpp
        shaker_sort.cpp
        odd_even_sort.cpp
        comb_sort.cpp
        selection_sort.cpp
        insertion_sort.cpp
        shell_sort.cpp
)
target_include_directories(sortlib PUBLIC .)