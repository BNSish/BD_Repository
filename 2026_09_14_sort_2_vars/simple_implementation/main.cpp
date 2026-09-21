#include <iostream>

static void print_array(const char* comment, const int* arr, int size);

static void my_sort(int *arr, int size);

int main() {
	int size;
	std::cout << "Введите размер массива: ";
	std::cin >> size;

	if (size <= 0) {
		std::cout << "Недопустимый размер массива." << std::endl;
		return 1;
	}

	int* arr = new int[size];
	std::cout << "Введите элементы массива: ";
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	print_array("Первоначальный массив: ", arr, size);

	my_sort(arr, size);

	print_array("Отсортированный массив: ", arr, size);

	delete[] arr;
	return 0;
}

void print_array(const char* const comment, const int* arr, const int size) {
	std::cout << comment << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void my_sort(int *arr, const int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}