#include "../Function/QuickCard.h"
#define MAX_ARRAY 51000

using namespace std;
#ifndef MAIN_CPP_MATH_H
#define MAIN_CPP_MATH_H

class Math {
public:
    static double mean(double arr[], int size) {
        double sum = 0;
        double mean;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        mean = sum / size;
        return mean;

    }

    static double median(double *arr, int size) {
        int flag = size % 2;
        if (flag != 0) {
            double median = arr[((size - 1) / 2)];
            return median;
        } else {
            double median = ((arr[size / 2] + arr[(size / 2) + 1]) / 2);
            return median;
        }
    }
    static double mode(double *arr, int size) {
        int maxValue = 0, maxCount = 0, i, j;
        for (i = 0; i < size; ++i) {
            int count = 0;
            for (j = 0; j < size; ++j) {
                if (arr[j] == arr[i])
                    ++count;
            }
            if (count > maxCount) {
                maxCount = count;
                maxValue = arr[i];
            }
        }
        return maxValue;
    }

    static double variance(double arr[], int size, double mean_value) {
        double var = 0.0;
        for (int i = 0; i < size; i++) {
            var += pow((arr[i] - mean_value), 2);
            var = var / (size - 1);
        }
        return pow(var, 2);
    }


    static double kurtosis(double arr[], int size, double mean_value) {
        double kur = 0;
        //Calculate moment4 and moment2
        double m4 = 0;
        double m2 = 0;
        for (int i = 0; i < size; i++) {
            m4 += pow(arr[i] - mean_value, 4);
            m2 += pow(arr[i] - mean_value, 2);
        }
        kur = size * m4 / pow(m2, 2);
        return kur;
    }

    static double covariance(double arr_x[], double arr_y[], int size, double mean_x, double mean_y) {
        double cov_xy = 0;
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum = sum + ((arr_x[i] - mean_x) * (arr_y[i] - mean_y));
            cov_xy = sum / (size - 1);
        }
        return cov_xy;
    }

    static double Skewness(double arr[], int size, double mean_value) {
        double Skewness = 0;
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum = (arr[i] - mean_value) * (arr[i] - mean_value) * (arr[i] - mean_value);
        }
        return Skewness = sum / (size * variance(arr, size, mean_value) * variance(arr, size, mean_value)
                                 * variance(arr, size, mean_value) * variance(arr, size, mean_value));
    }

    static double ThirdQuartile(double arr[], int size) {
        double Q3 = arr[(size * 3 / 4)];
        if ((fmod(arr[size * 3 / 4], 2)) == 0) {
            Q3 = (Q3 + arr[(size * 3 / 4 - 3 / 4)]) / 2;
        } else {
            Q3 = (Q3 + arr[(size * 3 / 4)]) / 2;
        }
        return Q3;
    }

    static double Coefficient(double arr_x[], double arr_y[], int size) {
        double sumX = 0, sumY = 0, sumXY = 0;
        double sumX2 = 0, sumY2 = 0;
        double CC = 0;
        for (int i = 0; i < size; i++) {
            sumX = sumX + arr_x[i];
            sumY = sumY + arr_y[i];
            sumXY = sumXY + arr_x[i] * arr_y[i];

            sumX2 = sumX2 + arr_x[i] * arr_x[i];
            sumY2 = sumY2 + arr_y[i] * arr_y[i];
        }

        CC = (size * sumXY - sumX * sumY)
             / sqrt((size * sumX2 - sumX * sumX) * (size * sumY2 - sumY * sumY));

        return CC;
    }

    static double Regression(double arr_x[], double arr_y[], double mean_x, double mean_y, int size) {
        double a, b;

        a = Coefficient(arr_x, arr_y, size) * variance(arr_y, size, mean_y) / variance(arr_x, size, mean_x);

        b = mean_y - a * mean_x;

        return a, b;
    }

};



#endif //MAIN_CPP_MATH_H
