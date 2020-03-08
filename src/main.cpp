#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "bubblesort/Bubblesort.h"

using namespace std;

int main() {

    ofstream file;
    string timestamp = to_string(time(NULL));
    file.open("results_" + timestamp + ".csv");

    if (!file.is_open()) {
        cout << "Failed to open results file." << endl;
        return 1;
    }

    const vector<int> GROUPS = {1000, 10000, 100000, 1000000};
    const int TIMES_EACH = 10;

    vector<int> results;

    for (int n: GROUPS) {

        results.clear();

        // Instantiate array
        int* arr = new int[n];

        // Populating the array descending order
        for (int i = 0; i < n; i++) {
            arr[i] = (-i + n);
        }

        for (int i = 0; i < TIMES_EACH; i++) {

            // Running the algorithm and measuring time
            auto initialTime = chrono::high_resolution_clock::now();
            Bubblesort::sort(arr, n);
            auto finalTime = chrono::high_resolution_clock::now();

            // Calculating time and printing results
            auto executionTime =
                    chrono::duration_cast<chrono::milliseconds>(finalTime - initialTime);

            results.push_back(executionTime.count());

        }

        // Deallocating array
        delete[] arr;

        // Calculating the avg result
        int sumResult = 0;
        for (int result: results) {
            sumResult += result;
        }
        int avgResult = (double) sumResult / results.size();

        // Writing result to file
        cout << n << ";" << avgResult << endl;
        file << n << ";" << avgResult << endl;

    }

    file.close();
    return 0;

}
