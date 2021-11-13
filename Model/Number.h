#ifndef MAIN_CPP_NUMBER_H
#define MAIN_CPP_NUMBER_H
//this
#include "Function/QuickCard.h"
#include "../Function/Math.h"
#include<fstream>

#define MAX_ARRAY 51000

static const string data_file = R"(C:\Users\Asus\Desktop\GA1C++\Data\data1.csv)";

class Number {
    int x{};
    int y{};
public:
    static void get_data();
    static void get_value(const string &path);

    static double calculate_mean_x();

    static double calculate_mean_y();

    static void calculate_median();

    static void calculate_mode();

    static void calculate_Variance();
    static void calculate_Mad();
    static void calculate_Kurtosis();


    int getX() const {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        this->y = y;
    }

    virtual ~Number();
};

static Number num;

static struct data_calling_y {
    int count_Y = 1;
    Number *ARRAY_Y = new Number[MAX_ARRAY];
    Number *y_pointer = ARRAY_Y;

    double *ARRAY_VALUE_OF_Y = new double[MAX_ARRAY];
    double *pty = ARRAY_VALUE_OF_Y;
} data_y;

struct data_calling_x {
    int count_X = 1;
    Number *ARRAY_X = new Number[MAX_ARRAY];
    double *ARRAY_VALUE_OF_X = new double[MAX_ARRAY];
    Number *x_pointer = ARRAY_X;
    double *ptx = ARRAY_VALUE_OF_X;
} data_x;



void Number::get_value(const string &path) {
    ifstream inFile(path);
    string line;
    if (!inFile) {
        cout << "That file can't open." << endl;
    } else {
        while (getline(inFile, line, ',')) {
            size_t tab = line.find('\n');
            if (tab != std::string::npos) {
                string string_x_number = line.substr(tab + 1);
                (data_x.ARRAY_X + data_x.count_X)->setX(atoi(string_x_number.c_str()));
                data_x.count_X++;

                string string_y_number = line.substr(0, tab);
                (data_y.y_pointer + data_y.count_Y)->setY(atoi(string_y_number.c_str()));
                data_y.count_Y++;
            }
        }
        for (int i = 1; i < data_x.count_X; i++) {
            *(data_x.ptx + i) = (data_x.x_pointer + i)->getX();
            *(data_y.pty + i) = (data_y.y_pointer + i)->getY();
        }

        function.quickSort(data_x.ptx, 0, data_x.count_X);
        function.quickSort(data_y.pty, 0,data_y.count_Y);
    }
    inFile.close();
}

void Number::get_data() {
    num.get_value(data_file);
}


void Number::calculate_median() {
    cout << "median and Median" << endl;
    cout << "median_x = { " << math.median(data_x.ptx, data_x.count_X - 2) << " }" << endl;
    cout << "median_y = { " << math.median(data_y.pty, data_y.count_Y - 2) << " }" << endl;
}

void Number::calculate_mode() {
    cout << "Mode" << endl;
    cout << "mode_x = { " << math.Mode(data_x.ptx, data_x.count_X - 2) << " }" << endl;
    cout << "mode_y = { " << math.Mode(data_y.pty, data_y.count_Y - 2) << " }" << endl;
}


double Number::calculate_mean_x() {
    double sumX = 0;
    double mean;
    for (int i = 0; i < data_x.count_X; i++) {
        sumX += data_x.ARRAY_X[i].getX();
    }
    mean = sumX / (data_x.count_X - 2);
    return mean;
}

double Number::calculate_mean_y() {
    double sumY = 0;
    double mean_Y;
    for (int i = 0; i < data_y.count_Y; i++) {
        sumY += data_y.ARRAY_Y[i].getY();
    }
    mean_Y = sumY / (data_y.count_Y - 2);
    return mean_Y;
}

void Number::calculate_Variance() {
    cout << "Variance" << endl;
    double mean_of_x = calculate_mean_x();
    double mean_of_y = calculate_mean_y();
    double variance_x = math.variance(data_x.ptx, data_x.count_X - 2, mean_of_x);
    double variance_y = math.variance(data_y.pty, data_y.count_Y - 2, mean_of_y);
    cout << "Variance_x = { " << variance_x << " }" << endl;
    cout << "Variance_y = { " << variance_y << " }" << endl;
    double st_x = sqrt(variance_x);
    double st_y = sqrt(variance_y);
    cout << "stdev_x = { " << st_x << " }" << endl;
    cout << "stdev_y = { " << st_y << " }" << endl;
}

void Number::calculate_Mad(){
    cout << "MAD" << endl;
    double mean_of_x = calculate_mean_x();
    double mean_of_y = calculate_mean_y();
    cout << "mad_x = { " << math.mad(data_x.ptx, data_x.count_X - 2, mean_of_x) << " }" << endl;
    cout << "mad_y = { " << math.mad(data_y.pty, data_y.count_Y - 2, mean_of_y) << " }" << endl;
}

void Number::calculate_Kurtosis(){
    cout << "Kurtosis" << endl;
    double mean_of_x = calculate_mean_x();
    double mean_of_y = calculate_mean_y();
    cout << "kurtosis_x = { " << math.covariance(data_x.ptx, data_y.pty, data_x.count_X - 2, mean_of_x, mean_of_y) << " }" << endl;
}


Number::~Number() {
    cout << "s3777091 - HUYNH DAC TAN DAT" << endl;
}

#endif //MAIN_CPP_NUMBER_H