
#include<iostream>
#include "Model/STACK.h"
#include "Function/Math.h"

using namespace std;
int main() {
    try {
        string data_file = R"(C:\Users\Asus\Desktop\GA1C++\Data\data1.csv)";
        stk.get_data(data_file);
        stk.sort();
        math.mean<double>(&mt.mean_x, &mt.mean_y);

        math.median<double>(&mt.median_x, &mt.median_y);
        cout << "median_x= "<< mt.median_x << ", "<< "median_y= " << mt.median_y << endl;

        math.mode<double>(&mt.mode_x, &mt.mode_y);
        cout << "mode_x= "<< mt.mode_x << ", "<< "mode_y= " << mt.mode_y << endl;

    } catch (const system_error &error) {
        std::cerr << "file system error!" << error.what() << '\n';
    } catch (const runtime_error &error) {
        std::cerr << "run time err!" << error.what() << '\n';
    }
}


