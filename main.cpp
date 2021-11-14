#include<iostream>
#include<string>
#include "Model/Number.h"
#include "Function/Math.h"

using namespace std;

int main() {
    try {
        num.get_data();
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
            case 'c' :
                num.calculate_Variance();
                break;
            case 'd':
                num.calculate_Mad();
                break;
            case 'e':
                num.calculate_Kurtosis();
                break;
            case 'f':
                num.display();
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