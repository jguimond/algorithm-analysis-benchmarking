/* *************************************************
*  Name: Josh Guimond
*  Assignment: Demonstration Code
*  Purpose: Header file for main. All directives for
*  main go here.
************************************************* */

#ifndef MAIN_CLASSES_H
#define MAIN_CLASSES_H

#include <iostream>

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n);

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high);

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right);

// Helper function to merge subarrays for Merge Sort
void merge(int arr[], int left, int mid, int right);

// Utility function to copy one array to another
void copyArray(int src[], int dest[], int n);

// Function to print the array
void printArray(int arr[], int size);

#endif /* MAIN_CLASSES_H */
