//Code from Dathuynh
#ifndef MAIN_CPP_STACK_H
#define MAIN_CPP_STACK_H

#include "../Function/QuickCard.h"

#define ST STACK::


//This code utilize the Algorithm of Stack to add data from csv file
using namespace std;

class STACK {
public:
    STACK();

    static auto push(double x, double y, const string &data_file);

    static int isEmpty();

    static int isFull();

    static void get_data(const string &data_file);

    static int sort();

    static bool isValid(const string &val);

    static bool emptyCell(const string &val);

    static void get_data_line(const string &data_file);

    static void update(const string &data_file);
};

//structure of Stack include top to know the max value of Stack maxSize is the limit of array
//and Two array data_x and data_y is the array to that is capacity of two value of x and y in csv file
static struct stack {
    int top{};
    int line{};
    int maxSize = 51000;
    double *data_x = new double[maxSize];
    double *data_y = new double[maxSize];
} st;

//Function to check is that Value in data.csv is empty or not?
bool ST emptyCell(const string &val) {
    if (val.empty()) {
        return true;
    } else
        return false;
}

//Stack implement method
ST STACK() {
    st.top = -1;
}

//Function checking is that empty Stack or not
int ST isEmpty() {
    if (st.top == -1)
        return 1;
    else
        return 0;
}

//Function checking input value in data.csv is wrong or not
bool ST isValid(const string &val) {
    const char *p = val.c_str();
    int dot_counter = 0;
    if ((*p) == '+' || (*p) == '-')p++;
    while ((*p) != '\0') {
        if ((*p) == '.') {
            dot_counter++;
            if (dot_counter > 1)
                return false;
        } else if ((*p) < '0' || (*p) > '9')
            return false;
        p++;
    }
    return true;
}

//Function to check in Stack is full or not
int ST isFull() {
    if (st.top == (st.maxSize - 1))
        return 1;
    else
        return 0;
}

//Function update array size while data size is bigger than defaults
void ST update(const string &data_file) {
    get_data_line(data_file);
    auto *temp_array_x = new double[st.line + 5];
    auto *temp_array_y = new double[st.line + 5];
    for (int i = 0; i < st.line; i++) {
        temp_array_x[i] = st.data_x[i];
        temp_array_y[i] = st.data_y[i];
    }
    delete[] st.data_x;
    delete[] st.data_y;
    st.data_x = temp_array_x;
    st.data_y = temp_array_y;
}

//Function to add data from x and y to Stack
auto ST push(double x, double y, const string &data_file) {
    if (isFull()) {
        system("color 0C");
        cout << "Your Data is Full now!! default capacity size is: " << st.maxSize
             << "\n" << "Our Program will update data size pls wait!!" << endl;
        update(data_file);
    }
    ++st.top;
    st.data_x[st.top] = x;
    st.data_y[st.top] = y;
}


//Call back from quickCard function that use to sort all data in array while start calculate.
//Why we need sort ?
//Sorting before start calculate or find something in big array that make it work faster
int ST sort() {
    while (!isEmpty()) {
        QuickCard::quickSort(st.data_x, 0, st.top);
        QuickCard::quickSort(st.data_y, 0, st.top);
        return 0;
    }
    cout << "Your Data is empty" << endl;
    return 1;
}

void ST get_data_line(const string &data_file) {
    ifstream inFile(data_file);
    string line;
    if (!inFile) {
        system("color 0C");
        cerr << "Failed to open files for input\n";
        exit(3);
        //Checking if fail to open file exit the code
    } else {
        // Explain this Algorithm in this line of code
        while (getline(inFile, line, '\n')) {
            st.line++;
        }
    }
    inFile.close();
}

//Function to read data from String file then add it in Stack
void ST get_data(const string &data_file) {
    ifstream inFile(data_file);
    string line;
    if (!inFile) {
        system("color 0C");
        cout << "Failed to open files " << data_file << " input\n" << endl;
        exit(3);
        //Checking if fail to open file exit the code
    } else {
        // Explain this Algorithm in this line of code
        while (getline(inFile, line, '\n')) {
            // while loop to get everything in this file.csv while it see the end of \n it will stop
            size_t tab = line.find(',');
            // tab is represented for to identify value string x and y
            //because in data file "x,y" x and y string identify by comma
            if (tab != std::string::npos) {
                string string_x_number = line.substr(0, tab);
                //substr from 0 to tab mean from first value of this string to comma
                //In this case mean 0, => 0 represent for x value and , is the end value
                string string_y_number = line.substr(tab + 1, '\n');
                //This case more similar to x value, Y value easy to know because it next to comma and last value is space
                //so ,0 , is first string + 1 mean y value and final of that value is space.
                if (!emptyCell(string_x_number) && (!emptyCell(string_y_number))) {
                    // Utilize to check string
                    if (isValid(string_x_number) && isValid(string_y_number)) {
                        char *endPtr_x;
                        double x = strtod(string_x_number.c_str(), &endPtr_x);
                        //exchange from x string to x number
                        char *endPtr_y;
                        double y = strtod(string_y_number.c_str(), &endPtr_y);
                        //exchange from y string to y number
                        push(x, y, data_file);
                        //add data to Stack
                    }
                }
            }
        }
    }
    inFile.close();
}

//Public Stack implement by the name stack
#endif