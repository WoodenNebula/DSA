#include <iostream>

// Assuming the array is sorted in ascending order
int search(const int* sortedArray, int len, int target) {
    int low = 0, high = len;
    int mid;
    do {
        mid = (low + high) / 2;
        int val = sortedArray[mid];
        if (val == target)
            return mid;
        else if (val > target)
            high = mid;
        else
            low = mid + 1;
    } while (low < high);
    return -1;
}


int main() {
    const int arr[] = { 1, 2, 4, 6, 7, 8, 9, 10, 23, 62, 75, 76, 99 };
    int length = sizeof arr / sizeof arr[0];

    for (int i = 0; i < length; i++) {
        int indx = search(arr, length, arr[i]);

        if (indx >= 0)
            std::cout << "Found " << arr[indx] << " at " << indx << std::endl;
        else
            std::cout << arr[i] << " not Found" << std::endl;
    }
}