
#include<iostream>
#include<iomanip>
#include "Model/STACK.h"
#include "Function/Math.h"

using namespace std;


void display(string Algorithm_a,double value_a, string Algorithm_b, double value_b){
    cout << Algorithm_a << ":" << setw(3)
    << value_a << setw(3) << "| " << setw(3)
    << Algorithm_b << " : " << setw(3)
    << value_b << setw(3) << "|" << endl;
}
int main() {
    try {
        string data_file = R"(C:\Users\Asus\Desktop\GA1C++\Data\data1.csv)";
        stack.get_data(data_file);
        stack.sort();

        Math::mean<double>(&mt.mean_x, &mt.mean_y);

        Math::median<double>(&mt.median_x, &mt.median_y);
        display("median_x",mt.median_x, "median_y", mt.median_y);

        Math::mode<double>(&mt.mode_x, &mt.mode_y);
        display("mode_x", mt.mode_x, "mode_y", mt.mode_y);

        Math::variance<double>(&mt.var_x, &mt.var_y);
        display("var_x", mt.var_x, "var_y", mt.var_y);

        Math::mad<double>(&mt.mad_x, &mt.mad_y);
        cout << "mad_x= " << mt.mad_x << ", " << "mad_y= " << mt.mad_y << endl;

        Math::ThirdQuartile<double>(&mt.Q3_x, &mt.Q3_y);
        cout << "Q3_x= " << mt.Q3_x << ", " << "q3_y= " << mt.Q3_y << endl;

        Math::Skewness<double>(&mt.Sk_x, &mt.Sk_y);
        cout << "skew_x= " << mt.Sk_x << ", " << "skew_y= " << mt.Sk_y << endl;

        Math::kurtosis<double>(&mt.Ku_x, &mt.Ku_y);
        cout << "kurt_x= " << mt.Ku_x << ", " << "kurt_y= " << mt.Ku_y << endl;

        Math::covariance<double>(&mt.Co_x_y);
        cout << "cov(x_y)= " << mt.Co_x_y << endl;

        Math::Coefficient<double>(&mt.Coefficient_x_y);
        cout << "r(x_y)= " << mt.Coefficient_x_y << endl;

        Math::Regression_a<double>(&mt.re_a);
        Math::Regression_b<double>(&mt.re_b);
        cout << "y = " << mt.re_a << "x" << " + " << mt.re_b << endl;

        cout
        << "s3777091 - HUYNH DAC TAN DAT" << "\n"
        <<"s3845565 - DO HUNG SON" << "\n"
        << "s3915177 - TRINH VAN MINH DUC"
        << endl;

    } catch (const system_error &error) {
        std::cerr << "file system error!" << error.what() << '\n';
    } catch (const runtime_error &error) {
        std::cerr << "run time err!" << error.what() << '\n';
    }
}


