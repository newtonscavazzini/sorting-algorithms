#include "SelectionSort.h"

void SelectionSort::sort(int *arr, int n) {

    for (int i = 0; i < n-1; i++) {

        int min = i;

        for (int j = i+1; j < n; j++) {

            if (arr[j] < arr[min]) {
                min = j;
            }

        }

        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;

    }

}
