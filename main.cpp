#include<iostream>
#include<string>
#include "Model/Number.h"
#include "Function/QuickCard.h"

using namespace std;
#define MAX_ARRAY 51000
static const string data_file = R"(C:\Users\Asus\Desktop\GA1C++\Data\data1.csv)";
struct data_calling_y {
    int count_Y = 1;
    Number *ARRAY_Y = new Number[MAX_ARRAY];
    Number *y_pointer = ARRAY_Y;
    float *ARRAY_VALUE_OF_Y = new float[MAX_ARRAY];
    float *pty = ARRAY_VALUE_OF_Y;
} data_y;

struct data_calling_x {
    int count_X = 1;
    Number *ARRAY_X = new Number[MAX_ARRAY];
    float *ARRAY_VALUE_OF_X = new float[MAX_ARRAY];
    Number *x_pointer = ARRAY_X;
    float *ptx = ARRAY_VALUE_OF_X;
} data_x;


static QuickCard function;
static Number num_function;


void get_x_value(const string &path) {
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
            }
        }
        for (int i = 1; i < data_x.count_X; i++) {
            *(data_x.ptx + i) = (data_x.x_pointer + i)->getX();
        }
        num_function.quickSort(data_x.ptx, 1, data_x.count_X);
    }
    inFile.close();
}

void get_y_value(const string &path) {
    ifstream inFile(path);
    string line;
    if (!inFile) {
        cout << "That file can't open." << endl;
    } else {
        while (getline(inFile, line, ',')) {
            size_t tab = line.find('\n');
            if (tab != '\n') {
                string string_y_number = function.exchange(line.substr(0, tab));
                (data_y.y_pointer + data_y.count_Y)->setY(atoi(string_y_number.c_str()));
                data_y.count_Y++;
                if (data_y.count_Y > MAX_ARRAY) {
                    delete[] data_y.ARRAY_VALUE_OF_Y;
                    float *ARRAY_VALUE_OF_Y = new float[MAX_ARRAY + 20];
                    data_y.pty = ARRAY_VALUE_OF_Y;
                }
            }
        }
        for (int i = 3; i < data_y.count_Y; i++) {
            *(data_y.pty + i) = (data_y.y_pointer + i)->getY();
        }
        num_function.quickSort(data_y.pty, 1, data_y.count_Y);
    }
    inFile.close();
}

int main() {
    try {
        get_y_value(data_file);
        get_x_value(data_file);
        int option;
        cout << "option: " << endl;
        cin >> option;
        //        int size_y = sizeof(array_value_of_y) / sizeof(array_value_of_y[0]);

        switch (option) {
            case 1 :
                cout << "median and Median" << endl;
                cout << "median_x = { " << num_function.median(data_x.ptx, data_x.count_X) << " }" << endl;
                cout << "median_y = { " << num_function.median(data_y.pty, data_y.count_Y) << " }" << endl;
                break;
            case 2 :
                cout << "Mode" << endl;
                break;
            default :
                cout << "Pls Try Again" << endl;
        }

    } catch (const system_error &error) {
        std::cerr << "file system error!" << error.what() << '\n';
    } catch (const runtime_error &error) {
        std::cerr << "run time err!" << error.what() << '\n';
    }
    return 0;
}