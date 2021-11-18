
#include<iostream>
#include<iomanip>
#include "Model/STACK.h"
#include "Function/Math.h"
using namespace std;

void display(string Algorithm_a, double value_a, string Algorithm_b, double value_b) {
    cout << "|"<< setprecision(6)
    << setw(0) << Algorithm_a << ": " 
    << setw(20-Algorithm_a.size()) <<value_a << "| "
    << Algorithm_b << ": "  << setw(20-Algorithm_b.size())
    << value_b  << "|" << endl;
}



int main() {
    try {
        string data_file = R"(../Data/data1.csv)";
        stack.get_data(data_file);
        stack.sort();
        system("color B0");
        cout << "Descriptive Statistics" << endl;
        cout << "------------------------------------------------" << endl;
        Math::mean<double>(&mt.mean_x, &mt.mean_y);
        display("mean_x",mt.mean_x,"mean_y", mt.mean_y);
   
        Math::median<double>(&mt.median_x, &mt.median_y);
        display("median_x",mt.median_x, "median_y", mt.median_y);
        
        Math::mode<double>(&mt.mode_x, &mt.mode_y);
        display("mode_x", mt.mode_x, "mode_y", mt.mode_y);
       
        Math::variance<double>(&mt.var_x, &mt.var_y);
        display("var_x", mt.var_x, "var_y", mt.var_y);
        display("stdev_x", sqrt(mt.var_x), "stdev_y", sqrt(mt.var_y));
        
        Math::mad<double>(&mt.mad_x, &mt.mad_y);
        display("mad_x", mt.mad_x , "mad_y", mt.mad_y);

        Math::ThirdQuartile<double>(&mt.Q3_x, &mt.Q3_y);
        display("Q3_x", mt.Q3_x, "Q3_y", mt.Q3_y);

        Math::Skewness<double>(&mt.Sk_x, &mt.Sk_y);
        display("skew_x", mt.Sk_x, "skew_y", mt.Sk_y);

        Math::kurtosis<double>(&mt.Ku_x, &mt.Ku_y);
        display("kurt_x", mt.Ku_x, "kurt_y", mt.Ku_y);

        cout << "------------------------------------------------" << endl;
        cout << "Inferential Statistics" << endl;

        Math::covariance<double>(&mt.Co_x_y);
        cout << setprecision(6) << "cov(x_y): " <<setw(12) << mt.Co_x_y << endl;


        Math::Coefficient<double>(&mt.Coefficient_x_y);
        cout << setprecision(6) << "r(x_y): " << setw(14) << mt.Coefficient_x_y << endl;

        Math::Regression_a<double>(&mt.re_a);
        Math::Regression_b<double>(&mt.re_b);
        cout << "y = " << mt.re_a << "x" << " + " << mt.re_b << endl;

        cout << "------------------------------------------------" << endl;

        cout
        <<"ASSIGNMENT 1GROUP<TT>" "\n"
        << "s3777091,s3777091@rmit.edu.vn - DAT HUYNH" << "\n"
        <<"s3845565,s3845565@rmit.edu.vn - SON DO" << "\n"
        << "s3915177,s3915177@rmit.edu.vn - DUC TRINH"
        << endl;

    } catch (const system_error &error) {
        std::cerr << "file system error!" << error.what() << '\n';
    } catch (const runtime_error &error) {
        std::cerr << "run time err!" << error.what() << '\n';
    }
}


