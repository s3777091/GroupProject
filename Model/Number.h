#ifndef MAIN_CPP_NUMBER_H
#define MAIN_CPP_NUMBER_H
//this
#include "Function/QuickCard.h"
#include<fstream>
#define MAX_ARRAY 51000

class Number {
    int x{};
    int y{};
public:
    static void get_y_value(const string &path);
    static void get_x_value(const string &path);
    int getX() const {
        return x;
    }

    void setX(int x) {
        this -> x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        this -> y = y;
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

void Number::get_y_value(const string &path) {
    ifstream inFile(path);
    string line;
    if (!inFile) {
        cout << "That file can't open." << endl;
    } else {
        while (getline(inFile, line, ',')) {
            size_t tab = line.find('\n');
            data_y.count_Y++;
            if (tab != '\n') {
                string string_y_number = QuickCard::exchange(line.substr(0, tab));
                (data_y.y_pointer + data_y.count_Y)->setY(atoi(string_y_number.c_str()));
                if (data_y.count_Y > MAX_ARRAY) {
                    auto *ARRAY_VALUE_OF_Y = new double[data_y.count_Y + 1000];
                    data_y.ARRAY_VALUE_OF_Y = ARRAY_VALUE_OF_Y;
                    for (int i = 3; i < data_y.count_Y; i++) {
                        ARRAY_VALUE_OF_Y[i] = data_y.ARRAY_VALUE_OF_Y[i];
                    }
                    delete[] data_y.ARRAY_VALUE_OF_Y;
                    data_y.ARRAY_VALUE_OF_Y = ARRAY_VALUE_OF_Y;
                }
            }
        }
        for (int i = 3; i < data_y.count_Y; i++) *(data_y.pty + i) = (data_y.y_pointer + i)->getY();
        function.quickSort(data_y.pty, 1, data_y.count_Y);
    }
    inFile.close();
}

struct data_calling_x {
    int count_X = 1;
    Number *ARRAY_X = new Number[MAX_ARRAY];
    double *ARRAY_VALUE_OF_X = new double[MAX_ARRAY];
    Number *x_pointer = ARRAY_X;
    double *ptx = ARRAY_VALUE_OF_X;
} data_x;


void Number::get_x_value(const string &path) {
    ifstream inFile(path);
    string line;
    if (!inFile) {
        cout << "That file can't open." << endl;
    } else {
        while (getline(inFile, line, ',')) {
            size_t tab = line.find('\n');
            data_x.count_X++;
            if (tab != std::string::npos) {
                string string_x_number = line.substr(tab + 1);
                (data_x.ARRAY_X + data_x.count_X)->setX(atoi(string_x_number.c_str()));
                if (data_x.count_X > MAX_ARRAY) {
                    auto *ARRAY_VALUE_OF_X = new double[data_x.count_X + 1000];
                    data_x.ARRAY_VALUE_OF_X = ARRAY_VALUE_OF_X;
                    for (int i = 3; i < data_x.count_X; i++) {
                        ARRAY_VALUE_OF_X[i] = data_x.ARRAY_VALUE_OF_X[i];
                    }
                    delete[] data_x.ARRAY_VALUE_OF_X;
                    data_x.ARRAY_VALUE_OF_X = ARRAY_VALUE_OF_X;
                }
            }
        }
        for (int i = 1; i < data_x.count_X; i++) *(data_x.ptx + i) = (data_x.x_pointer + i)->getX();
        function.quickSort(data_x.ptx, 1, data_x.count_X);
    }
    inFile.close();
}
Number::~Number() {
    cout << "s3777091 - HUYNH DAC TAN DAT" << endl;
}

#endif //MAIN_CPP_NUMBER_H