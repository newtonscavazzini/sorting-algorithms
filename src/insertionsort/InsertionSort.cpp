#include "InsertionSort.h"

void InsertionSort::sort(int *arr, int n) {

    int key;
    int j;

    for (int i = 1; i < n; i++) {

        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }

}
