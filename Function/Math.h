#include<iostream>
#include<string>
#include "Model/Number.h"

using namespace std;
#ifndef MAIN_CPP_MATH_H
#define MAIN_CPP_MATH_H


class Math {
public:

    static double mean(const double arr[], int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) { sum += arr[i]; }
        return (double) sum / (double) size;
    }

    static double median(double *arr, int size) {
        if (size % 2 != 0)
            return (double) arr[size / 2];
        return (double) (arr[(size - 1) / 2] + arr[size / 2]) / 2.0;
    }

    static double variance(const double a[], int n) {
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

    static double standardDeviation(double arr[],
                                    int n) {
        return sqrt(variance(arr, n));
    }


    static double kurtosis(double *x, int n) {
        int i;
        double sum = 0;
        double mean_x;

        // Calculate mean
        for (i = 0; i < n; i++) {
            sum += x[i];
        }
        mean_x = sum / n;
        double r = 0;
        double q = 0;
        for (i = 0; i < n; i++) {
            r += pow(x[i] - mean_x, 4);
            q += pow(x[i] - mean_x, 2);
        }

        double k = n * r / pow(q, 2);
        return k;
    }

    static double mode(double x[], int n) {
        int y[MAX_ARRAY];
        int i, j, k, m, cnt, max = 0, no_mode = 0;
        double num;
        for (k = 0; k < n; k++){
            cnt = 0;
            num = x[k];
            for (i = k; i < n; i++){
                if (num == x[i])
                    cnt++;
            }
            y[k] = cnt;
            if (cnt >= 2){
                no_mode++;
            }
        }
        if (no_mode == 0){
            cout << "This data set has no modes\n" << endl;
        }
        for (j = 0; j < n; j++){
            if (y[j] > max)
                max = y[j];
        }
        for (m = 0; m < n; m++) {
            if (max == y[m])
            {
                cout << x[m] << endl;
            }
        }
        return 0;
    }
};

static Math math;


#endif //MAIN_CPP_MATH_H
