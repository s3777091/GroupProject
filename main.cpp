#include<iostream>
#include "Model/STACK.h"

using namespace std;
int main() {
    try {
        stk.get_data();
        stk.sort();
        stk.printf_math();
    } catch (const system_error &error) {
        std::cerr << "file system error!" << error.what() << '\n';
    } catch (const runtime_error &error) {
        std::cerr << "run time err!" << error.what() << '\n';
    }

}