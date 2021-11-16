#include<iostream>
#include<string>
#include <math.h>
#include <fstream>
using namespace std;

#ifndef MAIN_CPP_ALLFUNCTION_H
#define MAIN_CPP_ALLFUNCTION_H

class QuickCard {
public:
    template<class T>
    static void Swap(T *a, T *b) {
        T t = *a;
        *a = *b;
        *b = t;
    }
    template<class P>
    static int partition (P *arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high- 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                Swap<double>(&arr[i], &arr[j]);
            }
        }
        Swap<double>(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    template<class Q>
    static void quickSort(Q *arr, int low, int high) {
        if (low < high) {
            int pi = partition<double>(arr, low, high);
            quickSort<double>(arr, low, pi - 1);
            quickSort<double>(arr, pi + 1, high);
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
