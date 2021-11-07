#ifndef MAIN_CPP_NUMBER_H
#define MAIN_CPP_NUMBER_H
//this
#include "Function/QuickCard.h"



#define MAX_ARRAY 51000


class Number {
    int x;
    int y;

public:
    int getX() const {
        return x;
    }

    void setX(int x) {
        Number::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Number::y = y;
    }

    void swap(float *a, float *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    float median(float arr[], int n) {
        if (n % 2 == 1)
            return arr[(n - 1) / 2];
        return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
    }
    int partition (float *arr, int low, int high) {
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

    void quickSort(float arr[], int low, int high) {
        if (low < high) {
            /* pi is partitioning index, arr[p] is now
            at right place */
            int pi = partition(arr, low, high);

            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void print_array(float arr[], int size) {
        int i;
        for (i=0; i < size; i++)
            cout << arr[i] <<  " ";
        cout << endl;
    }

};



#endif //MAIN_CPP_NUMBER_H