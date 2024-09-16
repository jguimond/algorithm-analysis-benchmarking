#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm> // For std::copy

using namespace std;
using namespace std::chrono;

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Now merge the sorted halves directly within the same function
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }
}


// Utility function to copy one array to another
void copyArray(int src[], int dest[], int n) {
    std::copy(src, src + n, dest);
}

// Utility function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {250, 78, 100, 34, 262, 182, 283, 131, 299, 138, 247, 276, 169, 290, 44, 176, 
        189, 102, 104, 293, 239, 143, 150, 284, 187, 11, 49, 222, 297, 156, 230, 55, 17, 45, 
        105, 99, 160, 216, 128, 209, 5, 279, 298, 163, 7, 25, 179, 92, 70, 245, 264, 269, 285, 
        88, 63, 165, 137, 241, 244, 65, 223, 149, 84, 208, 119, 59, 202, 135, 257, 171, 226, 
        185, 280, 193, 54, 20, 162, 174, 72, 122, 139, 9, 152, 204, 64, 148, 288, 120, 168, 
        118, 265, 38, 289, 151, 48, 124, 275, 56, 95, 86, 117, 175, 267, 252, 161, 14, 181, 
        198, 98, 215, 31, 233, 147, 166, 180, 264, 167, 79, 253, 210, 40, 153, 83, 110, 32, 
        16, 285, 239, 164, 27, 77, 85, 4, 132, 89, 91, 29, 111, 10, 271, 201, 203, 46, 71, 
        133, 12, 215, 140, 75, 57, 272, 281, 18, 211, 221, 68, 282, 212, 193, 219, 23, 228, 
        58, 240, 232, 276, 228, 42, 103, 237, 126, 61, 243, 286, 146, 251, 68, 43, 225, 218, 
        94, 28, 180, 115, 12, 288, 105, 99, 216, 178, 32, 219, 40, 122, 46, 264, 2, 199, 44, 
        12, 117, 1, 64, 81, 88, 93, 89, 209, 118, 158, 41, 157, 200, 20, 212, 194, 11, 69, 28, 
        86, 127, 277, 14, 271, 211, 41, 196, 60, 24, 253, 242, 67, 175, 236, 131, 156, 225, 
        107, 108, 205, 90, 112, 245, 229, 73, 177, 30, 214, 96, 297, 191, 9, 179, 136, 235, 
        53, 240, 39, 288, 234, 92, 24, 159, 60, 204, 207, 12, 20, 244, 132, 91, 69, 196, 140, 
        184, 211, 260, 37, 91, 165, 90, 123, 27, 193, 68, 17, 197, 280, 190, 275, 58, 109, 284, 108};

    int n = sizeof(arr) / sizeof(arr[0]);

    long long totalBubble = 0, totalQuick = 0, totalMerge = 0;

    cout << "Benchmarking sorting algorithms (in nanoseconds):\n\n";
    cout << "Run  |   Bubble Sort  |    Quick Sort  |    Merge Sort\n";
    cout << "------------------------------------------------------\n";

    for (int run = 1; run <= 10; run++) {
        int arrBubble[n], arrQuick[n], arrMerge[n];
        copyArray(arr, arrBubble, n);
        copyArray(arr, arrQuick, n);
        copyArray(arr, arrMerge, n);

        // Benchmark Bubble Sort
        auto startBubble = high_resolution_clock::now();
        bubbleSort(arrBubble, n);
        auto endBubble = high_resolution_clock::now();
        auto durationBubble = duration_cast<nanoseconds>(endBubble - startBubble).count();
        totalBubble += durationBubble;

        // Benchmark Quick Sort
        auto startQuick = high_resolution_clock::now();
        quickSort(arrQuick, 0, n - 1);
        auto endQuick = high_resolution_clock::now();
        auto durationQuick = duration_cast<nanoseconds>(endQuick - startQuick).count();
        totalQuick += durationQuick;

        // Benchmark Merge Sort
        auto startMerge = high_resolution_clock::now();
        mergeSort(arrMerge, 0, n - 1);
        auto endMerge = high_resolution_clock::now();
        auto durationMerge = duration_cast<nanoseconds>(endMerge - startMerge).count();
        totalMerge += durationMerge;

        // Output the results
        cout << setw(3) << run << "  |  " 
             << setw(12) << durationBubble << "  |  "
             << setw(12) << durationQuick << "  |  "
             << setw(12) << durationMerge << endl;
    }

    // Print the average time for each sort
    cout << "------------------------------------------------------\n";
    cout << " Avg |  " 
         << setw(12) << totalBubble / 10 << "  |  "
         << setw(12) << totalQuick / 10 << "  |  "
         << setw(12) << totalMerge / 10 << "\n" << endl;

    return 0;
}