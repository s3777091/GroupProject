#include<iostream>
#include<string>
#include <math.h>
#include <fstream>
using namespace std;

#ifndef MAIN_CPP_ALLFUNCTION_H
#define MAIN_CPP_ALLFUNCTION_H

class QuickCard {
public:
    static void swap(double *a, double *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    static int partition (double *arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high- 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    static void quickSort(double *arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void print_array(double arr[], int size) {
        int i;
        for (i=0; i < size; i++)
            cout << arr[i] <<  endl;
    }
};

static QuickCard function;


#endif
