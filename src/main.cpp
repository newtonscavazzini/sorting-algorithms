#include <iostream>
#include "bubblesort/Bubblesort.h"

using namespace std;

int main() {

    int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

    Bubblesort::sort(arr, 10);

    for (int i : arr)
        cout << i << " ";

}
