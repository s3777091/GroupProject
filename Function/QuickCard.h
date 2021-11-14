#include<iostream>
#include<string>

using namespace std;

#ifndef MAIN_CPP_ALLFUNCTION_H
#define MAIN_CPP_ALLFUNCTION_H

class QuickCard {

public:
    static bool isNumber(const string& str) {
        for (char c: str) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    static string exchange(string value) {
        if (value == " ") {
            string t = nullptr;
            return t;
        } else {
            return value;
        }
    }

    static void swap(double *a, double *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    int partition (double *arr, int low, int high) {
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

    void quickSort(double *arr, int low, int high) {
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
