#include "../Function/QuickCard.h"
#include "../Model/STACK.h"

using namespace std;
#ifndef MAIN_CPP_MATH_H
#define MAIN_CPP_MATH_H


class Math : public STACK {
public:
    virtual ~Math();
    template<typename T>
    static void mean(T *mean_x, T *mean_y) {
        T sum_x = 0;
        for (int i = 0; i < st.top; i++) {
            sum_x += st.data_x[i];
        }
        *mean_x = sum_x / st.top;
        T sum_y = 0;
        for (int j = 0; j < st.top; j++) {
            sum_y += st.data_y[j];
        }
        *mean_y = sum_y / st.top;
    }

    template<typename m>
    static void median(m *median_x, m *median_y) {
        int flag = st.top % 2;
        if (flag != 0) {
            *median_x = st.data_x[((st.top - 1) / 2)];
            *median_y = st.data_y[((st.top - 1) / 2)];
        } else {
            *median_x = ((st.data_x[st.top / 2] + st.data_x[(st.top / 2) + 1]) / 2);
            *median_y = ((st.data_y[st.top / 2] + st.data_y[(st.top / 2) + 1]) / 2);
        }
    }

    template<typename F>
    static void mode(F *mode_x, F *mode_y) {
        int maxCount_x = 0, maxCount_y = 0;
        for (int i = 0; i < st.top; ++i) {
            int count_x = 0;
            int count_y = 0;
            for (int j = 0; j < st.top; ++j) {
                if (st.data_x[j] == st.data_x[i])
                    ++count_x;
                if (st.data_y[j] == st.data_y[i])
                    ++count_y;
            }
            if (count_x > maxCount_x) {
                maxCount_x = count_x;
                *mode_x = st.data_x[i];
            } else if (count_y > maxCount_y) {
                maxCount_y = count_y;
                *mode_y = st.data_y[i];
            }
        }
    }

    static double variance(double arr[], int size, double mean_value) {
        double var = 0.0;
        double dev = 0.0;
        for (int i = 1; i < size+1; i++) {
            dev += pow((arr[i] - mean_value), 2);
        }
        var = dev / (size - 1);
        return var;
    }


    static double kurtosis(double arr[], int size, double mean_value) {
        double kur = 0;
        //Calculate moment4 and moment2
        double m4 = 0;
        double m2 = 0;
        double s = sqrt(variance(arr, size, mean_value));
        for (int i = 1; i < size+1; i++) {
            m4 += pow((arr[i] - mean_value)/s,4);
        }
        kur = (m4 / size) - 3;
        return kur;
    }

    static double covariance(double arr_x[], double arr_y[], int size, double mean_x, double mean_y) {
        double cov_xy = 0;
        double sum = 0;
        for (int i = 1; i < size +1; i++) {
            sum += ((arr_x[i] - mean_x) * (arr_y[i] - mean_y));
        }
        cov_xy = sum / (size - 1);
        return cov_xy;
    }

    static double mad(double arr[], int size, double mean_value) {
        double sum = 0;
        for (int i = 1; i < size; i++) {
            sum += abs(arr[i] - mean_value);
        }
        return sum / size;
    }

    static double Skewness(double arr[], int size, double mean_value) {
        double Skewness = 0;
        double sum = 0;
        double s = sqrt(variance(arr, size, mean_value));
        for (int i = 1; i < size; i++) {
            sum += pow((arr[i] - mean_value)/s,3);
        }
        return Skewness = sum / size;
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
        for (int i = 1; i < size+1; i++) {
            sumX += arr_x[i];
            sumY += arr_y[i];
            sumXY += (arr_x[i] * arr_y[i]);

            sumX2 += (arr_x[i] * arr_x[i]);
            sumY2 +=( arr_y[i] * arr_y[i]);
        }

        CC = (size * sumXY - sumX * sumY)
             / sqrt((size * sumX2 - sumX * sumX) * (size * sumY2 - sumY * sumY));

        return CC;
    }

    static double Regression_a(double arr_x[], double arr_y[], double mean_x, double mean_y, int size) {
        double a;

        a = (Coefficient(arr_x, arr_y, size) * sqrt(variance(arr_y, size, mean_y)))/ sqrt(variance(arr_x, size, mean_x));


        return a;
    }
    static double Regression_b(double arr_x[], double arr_y[], double mean_x, double mean_y, int size) {
        double b;
        b = mean_y - (Regression_a(arr_x, arr_y, mean_x, mean_y, size)) * mean_x;
        return b;
    }
};
static struct math_struct{
    double mean_x = st.data_x[0], mean_y = st.data_y[0];
    double median_x = st.data_x[0], median_y = st.data_y[0];
    double mode_x = st.data_x[0], mode_y = st.data_y[0];
} mt;


Math::~Math() {
    cout << "s3777091 - HUYNH DAC TAN DAT" << endl;
}

static Math math;

#endif //MAIN_CPP_MATH_H
