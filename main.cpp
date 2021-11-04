#include<iostream>
#include<string>
#include "Model/Number.h"
#include "Function/QuickCard.h"

using namespace std;
#define MAX_ARRAY 51000
#define labelY 1
#define labelX 1

static const string data_file = R"(C:\Users\Asus\Desktop\GA1C++\Data\data1.csv)";
static int count_X = labelY;
static int count_Y = labelX;
static Number ARRAY_X[MAX_ARRAY];
static Number ARRAY_Y[MAX_ARRAY];

static float array_value_of_y[MAX_ARRAY];
static float array_value_of_x[MAX_ARRAY];
static QuickCard function;

int get_x_value(const string &path) {
    ifstream inFile(path);
    string line;
    if (!inFile) {
        cout << "That file can't open." << endl;
        return 0;
    } else {
        while (getline(inFile, line, ',')) {
            size_t tab = line.find('\n');
            if (tab != std::string::npos) {
                string string_x_number = line.substr(tab + 1);
                int x = function.string_to_integer(string_x_number);
                ARRAY_X[count_X].setX(x);
                count_X++;
            }
        }
    }
    inFile.close();
    return 0;
}

int get_y_value(const string &path) {
    ifstream inFile(path);
    string line;
    if (!inFile) {
        cout << "That file can't open." << endl;
        return 0;
    } else {
        while (getline(inFile, line, ',')) {
            size_t tab = line.find('\n');
            if (tab != '\n') {
                string string_y_number = line.substr(0, tab);
                int y = function.string_to_integer(string_y_number);
                ARRAY_Y[count_Y].setY(y);
                count_Y++;
            }
        }
    }
    inFile.close();
    return 0;
}

int main() {
    try {
        get_y_value(data_file);
        get_x_value(data_file);
        for (int i = 3; i < count_Y; i++) {
            array_value_of_y[i] = ARRAY_Y[i].getY();
        }
        for (int i = 1; i < count_X; i++) {
            array_value_of_x[i] = ARRAY_X[i].getX();
        }

        int size_x = sizeof(array_value_of_x) / sizeof(array_value_of_x[0]);
        int size_y = sizeof(array_value_of_y) / sizeof(array_value_of_y[0]);
        int option;
        cout << "option: " << endl;
        cin >> option;

        switch (option) {
            case 1 :
                cout << "median and Median" << endl;
                cout << "median_x = { " << function.median(array_value_of_x, count_X) << " }" << endl;
                cout << "median_y = { " << function.median(array_value_of_y, count_Y) << " }" << endl;
                break;
            case 2 :
                cout << "mode Mode" << endl;
            case 3 :
                cout << "The variance or standard deviation" << endl;
                cout << "var_x = { " << function.variance(array_value_of_x, size_x) << " }" << endl;
                cout << "var_y = { " << function.variance(array_value_of_y, size_y) << " }" << endl;
                cout << "stdev_x = { " << function.standardDeviation(array_value_of_x, size_x) << " }" << endl;
                cout << "stdev_y = { " << function.standardDeviation(array_value_of_y, size_y) << " }" << endl;
                break;
            case 4 :
                cout << "MeanAbsolute Deviations(MAD)" << endl;
                cout << "mad_x = { " << function.deviation(array_value_of_x, size_x) << " }" << endl;
                cout << "mad_y = { " << function.deviation(array_value_of_y, size_y) << " }" << endl;
                break;
            case 6 :
                cout << "Skewness(x)" << endl;
                cout << "skew_x = { " << function.skewness(array_value_of_x, size_x) << " }" << endl;
                cout << "skew_y = { " << function.skewness(array_value_of_y, size_y) << " }" << endl;
                break;
            case 7 :
                cout << "kurtosis(x)" << endl;
                cout << "kurt_x = { " << function.kurtosis(array_value_of_x, size_x) << " }" << endl;
                cout << "kurt_y = { " << function.kurtosis(array_value_of_y, size_y) << " }" << endl;
                break;
            case 8 :
                cout << "Covariance(x)" << endl;
                cout << "cov(x_y) = { " << function.covariance(array_value_of_x, array_value_of_y, size_y) << " }"
                     << endl;
                break;
//            case 9 :
//                cout << "Pearson correlation coefficient(x)" << endl;
//                if (size_y == size_x)
//                cout << "r(x_y) = { " << function.correlationCoefficient(array_value_of_x, array_value_of_y,size_y) << " }" << endl;
//                break;
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
