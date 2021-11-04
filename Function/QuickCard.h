#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#ifndef MAIN_CPP_ALLFUNCTION_H
#define MAIN_CPP_ALLFUNCTION_H

class QuickCard {

public:

    void swap(float *a, float *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

/* This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot */
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

/* The main function that implements QuickSort
 * arr[] --> Array to be sorted,
 * low --> Starting index,
 * high --> Ending index
 */
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

    int string_to_integer(string str) {
        int num = 0, size;
        size = str.size();
        for (int i = 0, j = size; i < size; i++) num += (str[--j] - '0') * pow(10, i);
        return num;
    }

    float median(float arr[], int n) {
        if (n % 2 == 1)
            return arr[(n - 1) / 2];
        return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
    }

    float mean(float arr[], int size) {
        float sum = 0;
        for (int i = 0; i < size; i++)
            sum = sum + arr[i];
        return sum / size;
    }


    //calculate mean deviation
    float deviation(float arr[], int size) {
        float sum = 0;
        for (int i = 0; i < size; i++)
            sum = sum + abs(arr[i] - mean(arr, size));
        return sum / size;
    }

    float variance(float a[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        double meanT = (double) sum /
                       (double) n;

        double sqDiff = 0;
        for (int i = 0; i < n; i++)
            sqDiff += (a[i] - meanT) *
                      (a[i] - meanT);
        return sqDiff / n;
    }

    double standardDeviation(float arr[],
                             int n) {
        return sqrt(variance(arr, n));
    }

    float skewness(float arr[], int n) {
        // Find skewness using above formula
        float sum = 0;
        for (int i = 0; i < n; i++)
            sum = (arr[i] - mean(arr, n)) *
                  (arr[i] - mean(arr, n)) *
                  (arr[i] - mean(arr, n));
        return sum / (n * standardDeviation(arr, n) *
                      standardDeviation(arr, n) *
                      standardDeviation(arr, n) *
                      standardDeviation(arr, n));
    }

    float kurtosis(float *x, int n) {
        int i;
        double sum = 0;
        double mean_x = 0;

        // Calculate mean
        for (i = 0; i < n; i++) {
            sum += x[i];
        }
        mean_x = sum / n;
        double r = 0;
        double q = 0;
        for (i = 0; i < n; i++) {
            r += pow(x[i] - mean_x,  4);
            q += pow(x[i] - mean_x,  2);
        }

        double k = n *r / pow(q, 2);
        return k;
    }

    float covariance(float arr1[], float arr2[], int n){
        float sum = 0;
        for(int i = 0; i < n; i++)
            sum = sum + (arr1[i] - mean(arr1, n)) * (arr2[i] - mean(arr2, n));
        return sum / (n - 1);
    }

//    float correlationCoefficient(float X[], float Y[], int n)
//    {
//        int sum_X = 0, sum_Y = 0, sum_XY = 0;
//        int squareSum_X = 0, squareSum_Y = 0;
//        for (int i = 0; i < n; i++)
//        {
//            // sum of elements of array X.
//            sum_X = sum_X + X[i];
//            // sum of elements of array Y.
//            sum_Y = sum_Y + Y[i];
//            // sum of X[i] * Y[i].
//            sum_XY = sum_XY + X[i] * Y[i];
//            // sum of square of array elements.
//            squareSum_X = squareSum_X + X[i] * X[i];
//            squareSum_Y = squareSum_Y + Y[i] * Y[i];
//        }
//
//        // use formula for calculating correlation coefficient.
//        float corr = (float)(n * sum_XY - sum_X * sum_Y)
//                     / sqrt((n * squareSum_X - sum_X * sum_X)
//                            * (n * squareSum_Y - sum_Y * sum_Y));
//        return corr;
//    }
//correlationCoefficient have error

};


#endif
