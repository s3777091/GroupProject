//code from dathuynh
#ifndef MAIN_CPP_STACK_H
#define MAIN_CPP_STACK_H

#include "../Function/QuickCard.h"
using namespace std;

class STACK {
public:
    STACK();

    static auto push(int x, int y);

    static int isEmpty();

    static int isFull();

    static void get_data(const string& data_file);

    static int sort();
};

static struct stack {
    int top{};
    int maxSize = 51000;
    double *data_x = new double[maxSize];
    double *data_y = new double[maxSize];
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
    if (st.top == (st.maxSize - 1))
        return 1;
    else
        return 0;
}

auto STACK::push(int x, int y) {
    if (isFull()) {
        cout << "Your Data is to larger" << endl;
        return false;
    }
    ++st.top;
    st.data_x[st.top] = x;
    st.data_y[st.top] = y;
    return true;
}

int STACK::sort() {
    while (!isEmpty()) {
        QuickCard::quickSort<double>(st.data_x, 0, st.top);
        QuickCard::quickSort<double>(st.data_y, 0, st.top);
        return 0;
    }
    cout << "Your Data is empty" << endl;
    return 1;
}

static STACK stack;

void STACK::get_data(const string& data_file) {
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
                push(x, y);
            }
        }
    }
    inFile.close();
}

#endif