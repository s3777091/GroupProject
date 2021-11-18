#include<iostream>
#include<string>
#include <math.h>
#include <fstream>
using namespace std;

#ifndef MAIN_CPP_ALLFUNCTION_H
#define MAIN_CPP_ALLFUNCTION_H

class QuickCard {
public:
    static void Swap(double *a, double *b);
    static int partition (double *arr, int low, int high);
    static void quickSort(double *arr, int low, int high);
};

void QuickCard::Swap(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

int QuickCard::partition (double *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickCard::quickSort(double *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


#endif
