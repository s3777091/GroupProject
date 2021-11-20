#include<iostream>
#include<string>
#include <math.h>
#include <fstream>

using namespace std;
//Available at: https://rmit.instructure.com/courses/95403/files/20686257/download?download_frd=1 (Accessed:2 November 2021).

#ifndef MAIN_CPP_ALLFUNCTION_H
#define MAIN_CPP_ALLFUNCTION_H

class QuickCard {
public:
    static void Swap(double* a, double* b);

    static int partition(double* arr, int low, int high);

    static void quickSort(double* arr, int low, int high);
};
//create 3 function in QuickCard, QuickCard is the function adding in project

// A utility function to swap two elements
void QuickCard::Swap(double* a, double* b) {
    double t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot */
int QuickCard::partition(double* arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 * arr[] --> Array to be sorted,
 * low --> Starting index,
 * high --> Ending index
 */
void QuickCard::quickSort(double* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


#endif
