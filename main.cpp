#include<iostream>
#include<fstream>
#include<string>
#include "Number.h"

using namespace std;
#define MAX_ARRAY 51000
#define label 0

static const string data_file = R"(C:\Users\Asus\Desktop\GA1C++\Data\data2.csv)";
static int count_X = label;
static int count_Y = label;
static Number ARRAY_X[MAX_ARRAY];
static Number ARRAY_Y[MAX_ARRAY];


int string_to_integer(string str) {
    int num = 0, size;
    size = str.size();
    for (int i = 0, j = size; i < size; i++) num += (str[--j] - '0') * pow(10, i);
    return num;
}


int get_x_value(const string& path) {
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
                int x = string_to_integer(string_x_number);
                ARRAY_X[count_X].setX(x);
                count_X++;
            }
        }
    }
    inFile.close();
    return 0;
}

int get_y_value(const string& path) {
    ifstream inFile(path);
    string line;
    if (!inFile) {
        cout << "That file can't open." << endl;
        return 0;
    } else {
        while (getline(inFile, line, ',')) {
            size_t tab = line.find('\n');
            if (tab != std::string::npos) {
                string string_y_number = line.substr(0, tab);
                int y = string_to_integer(string_y_number);
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
        for (int i = 1; i < count_Y; i++) {
            cout << ARRAY_Y[i].getY() << endl;
        }
        cout << count_Y << endl;

    } catch (const system_error &error) {
        std::cerr << "file system error!" << error.what() << '\n';
    } catch (const runtime_error &error) {
        std::cerr << "run time err!" << error.what() << '\n';
    }

    return 0;
}
