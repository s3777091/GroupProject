//code from dathuynh
#ifndef MAIN_CPP_STACK_H
#define MAIN_CPP_STACK_H

#include "../Function/QuickCard.h"

using namespace std;

class STACK {
public:
    STACK();
    static auto push(double x, double y);
    static int isEmpty();
    static int isFull();
    static void get_data(const string& data_file);

    static int sort();

    static bool isValid(string val);
    
    static bool emptyCell(string val);
};

static struct stack {
    int top{};
    int maxSize = 51000;
    double *data_x = new double[maxSize];
    double *data_y = new double[maxSize];
} st;

bool STACK::emptyCell(string val) {
    if (val.empty()) {
        return true;
    }
    else
        return false;
}

STACK::STACK() {
    st.top = -1 ;
}


int STACK::isEmpty() {
    if (st.top == -1)
        return 1;
    else
        return 0;
}


bool STACK::isValid(string val) {
    const char* p = val.c_str();
    int dot_counter = 0; 
    if ((*p) == '+' || (*p) == '-')p++; 
    while ((*p) != '\0') 
    { 
        if ((*p) == '.') 
        { 
            dot_counter++; 
            if (dot_counter > 1)
                return false; 
        } 
        else if ((*p) < '0' || (*p) > '9')
            return false; p++; 
    }
    return true; 
}

int STACK::isFull() {
    if (st.top == (st.maxSize - 1))
        return 1;
    else
        return 0;
}

auto STACK::push(double x, double y) {
    if (isFull()) {
        cout << "Your Data is Full now" << endl;
    }
    ++st.top;
    st.data_x[st.top] = x;
    st.data_y[st.top] = y;
}

int STACK::sort() {
    while (!isEmpty()) {
        QuickCard::quickSort(st.data_x, 0, st.top);
        QuickCard::quickSort(st.data_y, 0, st.top);
        return 0;
    }
    cout << "Your Data is empty" << endl;
    return 1;
}
void STACK::get_data(const string& data_file) {
    ifstream inFile(data_file);
    string line;
    if (!inFile) {
        cerr << "failed to open files for input\n";
        exit( 3 );
    } else {
        while (getline(inFile, line, '\n')) {
            size_t tab = line.find(',');
            if (tab != std::string::npos) {
                string string_x_number = line.substr(0, tab);
                string string_y_number = line.substr(tab +1,'\n');
                if (!emptyCell(string_x_number) && (!emptyCell(string_y_number))) {
                    if (isValid(string_x_number) && isValid(string_y_number)) {
                        double x = atof(string_x_number.c_str());
                        double y = atof(string_y_number.c_str());
                        push(x, y);
                    }
                }
            }
        }
    }
    inFile.close();
}

static STACK stack;
#endif