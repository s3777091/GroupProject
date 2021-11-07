#include<iostream>
#include<string>
#include "Model/Number.h"
#include "Function/Math.h"

using namespace std;
static const string data_file = R"(C:\Users\Asus\Desktop\GA1C++\Data\data1.csv)";

int main() {
    try {
        num.get_y_value(data_file);
        num.get_x_value(data_file);
        char option;
        cout << "Option: " << endl;
        cin >> option;
        switch (option) {
            case 'a' :
                num.calculate_median();
                break;
            case 'b' :
                num.calculate_mode();
                break;
            default :
                cout << "Pls Try Again" << endl;
                break;
        }
    } catch (const system_error &error) {
        std::cerr << "file system error!" << error.what() << '\n';
    } catch (const runtime_error &error) {
        std::cerr << "run time err!" << error.what() << '\n';
    }

}