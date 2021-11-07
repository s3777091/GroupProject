#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#ifndef MAIN_CPP_ALLFUNCTION_H
#define MAIN_CPP_ALLFUNCTION_H

class QuickCard {

public:
    bool isNumber(const string str) {
        for (char c: str) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    string exchange(string value) {
        if (value == " ") {
            string t = 0;
            return t;
        } else {
            return value;
        }
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
            r += pow(x[i] - mean_x, 4);
            q += pow(x[i] - mean_x, 2);
        }

        double k = n * r / pow(q, 2);
        return k;
    }

    float covariance(float arr1[], float arr2[], int n) {
        float sum = 0;
        for (int i = 0; i < n; i++)
            sum = sum + (arr1[i] - mean(arr1, n)) * (arr2[i] - mean(arr2, n));
        return sum / (n - 1);
    }


};


#endif
