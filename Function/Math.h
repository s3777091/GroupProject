#include<iostream>
#include<string>

#define MAX_ARRAY 51000

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

    double Mode(double *array, int size) {
        int mode = -1, position = 0, highest;
        int frequency[MAX_ARRAY];

        for (int i = 0; i < size; i++)        //initailize all frequencies to 0
            *(frequency + i) = 0;

        for (int k = 0; k < size; k++) {
            for (int i = 1; i < size; i++) {
                if (*(array + k) == *(array + i) && &*(array + k) != &*(array + i))  //avoid counting itself in the scan
                    *(frequency + k) += 1;                 //increment the frequency of current number
            }
        }

        highest = *(frequency + 0);
        for (int count = 1; count < size; count++)    // get position of highest number
        {
            if (*(frequency + count) > highest) {
                highest = *(frequency + count);
                position = +count;                //get postion in frequency array, to put into numbers array
            }
        }

        for (int i = 0; i < size; i++)
            if (*(frequency + i) != *(frequency + (i + 1)) && (i + 1) < size) {
                mode = *(array + position);
                return mode;    //returns number that occurs most
            }
        return mode;
    }
};


static Math math;


#endif //MAIN_CPP_MATH_H
