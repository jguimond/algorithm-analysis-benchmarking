#include <iostream>
#include <algorithm> // For sort function
#include <cstdlib>   // For atoi()
#include <chrono>    // For measuring time in nanoseconds
using namespace std;
using namespace std::chrono;

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 15 == 0) cout << endl; // Print 15 elements per line
    }
    cout << endl;
}

// Binary Search function
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if target is at mid
        if (arr[mid] == target) {
            return mid;
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    // Target is not found in the array
    return -1;
}

// Function to handle searching and take array/target as argument
void searchArray(int arr[], int size, int target) {
    // Sort the array (since binary search requires sorted data)
    sort(arr, arr + size);

    // Print sorted array
    cout << "Sorted array:" << endl;
    printArray(arr, size);

    // Benchmarking binary search
    auto start = high_resolution_clock::now();
    int result = binarySearch(arr, size, target);
    auto end = high_resolution_clock::now();

    // Calculate time taken in nanoseconds
    auto duration = duration_cast<nanoseconds>(end - start).count();

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found" << endl;
    }

    cout << "Binary Search execution time: " << duration << " nanoseconds" << endl;
}

int main(int argc, char *argv[]) {
    // Static array dataset as provided
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
    
    const int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    if (argc > 1) {
        target = atoi(argv[1]);  // Convert argument to an integer target
    } else {
        target = arr[50]; // Pick an arbitrary target (50th element) if no argument is provided
    }

    // Call searchArray with the provided data and the target
    searchArray(arr, size, target);

    return 0;
}
