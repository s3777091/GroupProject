#include<iostream>
#include<string>
#include <math.h>
#define MAX_ARRAY 51000

using namespace std;
#ifndef MAIN_CPP_MATH_H
#define MAIN_CPP_MATH_H


class Math {
public:
    static double median(double *arr, int size) {
        int flag = size % 2;
        if (flag!= 0){
            double median = arr[((size - 1) / 2)];
            return median;
        }else{
            double median = ((arr[size / 2] + arr[(size / 2) +1]) /2);
            return median;
        }
    }

    static double Mode(double *arr, int size) {
        int mode = -1, position = 0, highest;
        int *frequency = new int[MAX_ARRAY];

        for (int i = 0; i < size; i++)        //initailize all frequencies to 0
            *(frequency + i) = 0;
        for (int k = 0; k < size; k++) {
            for (int i = 1; i < size; i++) {
                if (*(arr + k) == *(arr + i) && &*(arr + k) != &*(arr + i))  //avoid counting itself in the scan
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
                mode = *(arr + position);
                return mode;
            }
        return mode;
    }

    static double variance(double *a, int size, double mean_value) {
        double var = 0.0;
        for (int i = 0; i < size; i++){
            var += pow((a[i] - mean_value), 2);
            var = var / (size - 1);
        }
        return pow(var, 2);
    }

    static double mad(double a[], int size, double mean_value){
        double mad_value = 0;
        for (int i = 0; i < size; i++){
            mad_value = mad_value + abs(a[i] - mean_value);
            mad_value = mad_value / size;
        }
        return mad_value;
    }

    static double kurtosis(double *x, int n, double mean_value) {
        
    }


};


static Math math;


#endif //MAIN_CPP_MATH_H
