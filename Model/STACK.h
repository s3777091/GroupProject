//code from dathuynh
#ifndef MAIN_CPP_STACK_H
#define MAIN_CPP_STACK_H
#include "../Function/QuickCard.h"
using namespace std;
#define MAX_ARRAY 51000
class STACK{
public:
    STACK();
    static bool push(int x, int y);
    static int isEmpty();
    static int isFull();
    static void get_data(string data_file);
    static int sort();
};

static struct stack{
    int top;
    double* data_x = new double [MAX_ARRAY];
    double* data_y = new double [MAX_ARRAY];
} st;

STACK::STACK() {
    st.top = -1;
}

int STACK::isEmpty() {
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int STACK::isFull() {
    if (st.top == (MAX_ARRAY - 1))
        return 1;
    else
        return 0;
}

bool STACK::push(int x, int y) {
    if (isFull()) {
        cout << "Your Data is full" << endl;
        return false;
    }
    ++st.top;
    st.data_x[st.top] = x;
    st.data_y[st.top] = y;
    return true;
}

int STACK::sort() {
    while (!isEmpty()) {
        function.quickSort<double>(st.data_x, 0, st.top);
        function.quickSort<double>(st.data_y, 0, st.top);
        return 0;
    }
    cout << "Your Data is empty" << endl;
    return 1;
}

static STACK stk;
void STACK::get_data(string data_file) {
    ifstream inFile(data_file);
    string line;
    if (!inFile) {
        cout << "That file can't open." << endl;
    } else {
        while (getline(inFile, line, '\n')) {
            size_t tab = line.find(',');
            if (tab != std::string::npos) {
                string string_x_number = line.substr(0, tab);
                int x = atoi(string_x_number.c_str());
                string string_y_number = line.substr(tab + 1);
                int y = atoi(string_y_number.c_str());
                stk.push(x, y);
            }
        }
    }
    inFile.close();
}


#endif