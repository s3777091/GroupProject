//code from dathuynh
#ifndef MAIN_CPP_STACK_H
#define MAIN_CPP_STACK_H
#include "../Function/Math.h"

using namespace std;

class STACK : protected Math, protected QuickCard{
public:
    STACK();

    static bool push(int x, int y);

    static int isEmpty();

    static int isFull();

    static void displayItems();

    static void get_data();

    static int sort();

    static void printf_math();
    virtual ~STACK();
};


struct stack {
    int top;
    double* data_x = new double [MAX_ARRAY];
    double data_y[MAX_ARRAY];
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
        quickSort(st.data_x, 0, st.top);
        quickSort(st.data_y, 0, st.top);
        return 0;
    }
    cout << "Your Data is empty" << endl;
    return 1;
}


void STACK::printf_math() {
    double mean_x = mean(st.data_x, st.top);
    double mean_y = mean(st.data_y, st.top);

    cout << mean_x << " "<< mean_y << endl;
    cout << "median and Median" << endl;
    cout << "median_x = { " << median(st.data_x, st.top) << " }"
         << " _ " << "median_y = { " << median(st.data_y, st.top) << " }" << endl;

    cout << "mode_x = { " << mode(st.data_x, st.top) << " }"
         << " _ " << "mode_y = { " << mode(st.data_y, st.top) << " }" << endl;

}

static STACK stk;

void STACK::displayItems() {
    for (int i = 1; i < st.top + 1; i++) {
        cout << st.data_x[i] << " " << st.data_y[i] << endl;
    }
}

void STACK::get_data() {
    string data_file = R"(C:\Users\Asus\Desktop\GA1C++\Data\data1.csv)";
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


STACK::~STACK() {
    cout << "s3777091 - HUYNH DAC TAN DAT" << endl;
}


#endif
