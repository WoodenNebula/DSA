#include <iostream>

void BubbleSort(int* array, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void PrintArray(int* array, int len, const char* msg = "Array = ") {
    std::cout << msg << " [";

    for (int i = 0; i < len - 1 && len > 0; i++)
        std::cout << array[i] << ", ";

    std::cout << array[len - 1] << "]" << std::endl;
}

int main() {
    int arr[] = { 7, 2, 3, 4, 6, 5, 0, 8, 1, 9 };

    int len = (sizeof(arr)) / (sizeof(*arr));

    PrintArray(arr, len, "Unsorted Array = ");
    BubbleSort(arr, len);
    PrintArray(arr, len, "After Sorting = ");

    return 0;
}