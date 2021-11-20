#include<iostream>
#include<iomanip>
#include "STACK.h"
#include "Math.h"

using namespace std;

#define MT Math::

//Function of display format
void display(const string& Algorithm_a, double value_a, const string& Algorithm_b, double value_b) {
    cout << "|" << setprecision(4)
        << setw(0) << Algorithm_a << ": "
        << setw(20 - Algorithm_a.size()) << value_a << "| "
        << Algorithm_b << ": " << setw(20 - Algorithm_b.size())
        << value_b << "|" << endl;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Wrong input!";
        return 1;
    }
    string filename = argv[1]; //take in user input
    //try/catch err if programme critical contain problem continue to work and show err
    try {
        STACK stk;
        //Get all data and push it into Stack
        stk.get_data(filename);
        //Sort all data
        stk.sort();
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);

        //Color setting to make it look more attractive
        //Black text and light blue background
        system("color 09");
        cout << setw(20) << "Descriptive Statistics" << endl;
        MT Start_Algorithm();
        cout << "------------------------------------------------" << endl;
        display("mean_x", mt.mean_x, "mean_y", mt.mean_y);
        display("median_x", mt.median_x, "median_y", mt.median_y);
        display("mode_x", mt.mode_x, "mode_y", mt.mode_y);
        display("var_x", mt.var_x, "var_y", mt.var_y);
        display("stdev_x", sqrt(mt.var_x), "stdev_y", sqrt(mt.var_y));
        display("mad_x", mt.mad_x, "mad_y", mt.mad_y);
        display("Q3_x", mt.Q3_x, "Q3_y", mt.Q3_y);
        display("skew_x", mt.Sk_x, "skew_y", mt.Sk_y);
        display("kurt_x", mt.Ku_x, "kurt_y", mt.Ku_y);
        cout << "------------------------------------------------" << endl;
        cout << "Inferential Statistics" << endl;
        cout << setprecision(4) << "cov(x_y): " << setw(12) << mt.Co_x_y << endl;
        cout << setprecision(4) << "r(x_y): " << setw(14) << mt.Coefficient_x_y << endl;
        cout << "y = " << mt.re_a << "x" << " + " << mt.re_b << endl;
        cout << "------------------------------------------------" << endl;
        //Show All student who contribute to this project
        cout
            << "ASSIGNMENT1 GROUP<G5>" "\n"
            << "s3777091,s3777091@rmit.edu.vn - DAT HUYNH" << "\n"
            << "s3845565,s3845565@rmit.edu.vn - SON DO" << "\n"
            << "s3915177,s3915177@rmit.edu.vn - DUC TRINH"
            << endl;

    }
    catch (const system_error& error) {
        system("color 0C");
        std::cerr << "file system error!" << error.what() << '\n';
    }
    catch (const runtime_error& error) {
        system("color 0C");
        std::cerr << "run time err!" << error.what() << '\n';
    }
}