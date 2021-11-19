#include<iostream>
#include<iomanip>
#include "Model/STACK.h"
#include "Function/Math.h"
using namespace std;

#define MT Math::

//Function of display format
void display(string Algorithm_a, double value_a, string Algorithm_b, double value_b) {
    cout << "|"<< setprecision(4)
    << setw(0) << Algorithm_a << ": " 
    << setw(20-Algorithm_a.size()) <<value_a << "| "
    << Algorithm_b << ": "  << setw(20-Algorithm_b.size())
    << value_b  << "|" << endl;
}


string get_path(string file_name) {
    string path = __FILE__;
    path.replace(path.end() - 8, path.end(), "").append(file_name);
    return path;
}

int main() {
    //try/catch err if programme critical contain problem continue to work and show err
    try {
        //Get all data and push it into Stack
        stack.get_data(get_path("data1.csv"));
        //Sort all data
        stack.sort();
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);

        //Color setting to make it look more attractive
        //Black text and light blue background
        system("color 09");
        cout << "Descriptive Statistics" << endl;
        cout << "------------------------------------------------" << endl;
        MT mean<double>(&mt.mean_x, &mt.mean_y);
        display("mean_x",mt.mean_x,"mean_y", mt.mean_y);

        MT median<double>(&mt.median_x, &mt.median_y);
        display("median_x",mt.median_x, "median_y", mt.median_y);

        MT mode<double>(&mt.mode_x, &mt.mode_y);
        display("mode_x", mt.mode_x, "mode_y", mt.mode_y);

        MT variance<double>(&mt.var_x, &mt.var_y);
        display("var_x", mt.var_x, "var_y", mt.var_y);
        display("stdev_x", sqrt(mt.var_x), "stdev_y", sqrt(mt.var_y));

        MT mad<double>(&mt.mad_x, &mt.mad_y);
        display("mad_x", mt.mad_x , "mad_y", mt.mad_y);

        MT ThirdQuartile<double>(&mt.Q3_x, &mt.Q3_y);
        display("Q3_x", mt.Q3_x, "Q3_y", mt.Q3_y);

        MT Skewness<double>(&mt.Sk_x, &mt.Sk_y);
        display("skew_x", mt.Sk_x, "skew_y", mt.Sk_y);

        MT kurtosis<double>(&mt.Ku_x, &mt.Ku_y);
        display("kurt_x", mt.Ku_x, "kurt_y", mt.Ku_y);

        cout << "------------------------------------------------" << endl;
        cout << "Inferential Statistics" << endl;

        MT covariance<double>(&mt.Co_x_y);
        cout << setprecision(4) << "cov(x_y): " <<setw(12) << mt.Co_x_y << endl;


        MT Coefficient<double>(&mt.Coefficient_x_y);
        cout << setprecision(4) << "r(x_y): " << setw(14) << mt.Coefficient_x_y << endl;

        MT Regression_a<double>(&mt.re_a);
        MT Regression_b<double>(&mt.re_b);
        cout << "y = " << mt.re_a << "x" << " + " << mt.re_b << endl;

        cout << "------------------------------------------------" << endl;
//Show All student who contribute to this project
        cout
        <<"ASSIGNMENT1 GROUP<G5>" "\n"
        << "s3777091,s3777091@rmit.edu.vn - DAT HUYNH" << "\n"
        <<"s3845565,s3845565@rmit.edu.vn - SON DO" << "\n"
        << "s3915177,s3915177@rmit.edu.vn - DUC TRINH"
        << endl;

    } catch (const system_error &error) {
        system("color 0C");
        std::cerr << "file system error!" << error.what() << '\n';
    } catch (const runtime_error &error) {
        system("color 0C");
        std::cerr << "run time err!" << error.what() << '\n';
    }
}


