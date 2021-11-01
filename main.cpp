#include<iostream>
#include<fstream>
#include<string>
#include <sstream>

using namespace std;

class Value {
    int x;
    int y;
public:

    void setValueY(string path);

    void setValueX(string path);

    int getX() const {
        return x;
    }

    void setX(int x) {
        Value::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Value::y = y;
    }

    void display_Y() {
        cout << getY() << endl;
    }

    void display_X() {
        cout << getX() << endl;
    }


};


int string_to_integer(string str) {
    int num = 0, size = str.size();

    for (int i = 0, j = size; i < size; i++)
        num += (str[--j] - '0') * pow(10, i);

    return num;

}

void Value::setValueY(string path) {
    string line;
    ifstream openData(path);


    if (openData.is_open()) {
        cout << "open file " << path << endl;
        while (getline(openData, line, ',')) {
            size_t tab = line.find("\n");
            if (tab != std::string::npos) {
                string string_y_number = line.substr(0, tab);
                int y = string_to_integer(string_y_number);
                cout << y << endl;
            }
        }
    } else {
        cout << "Can't open file" << endl;
    }
    openData.close();

}

void Value::setValueX(string path) {
    string line;
    ifstream openData(path);
    if (openData.is_open()) {
        cout << "open file " << path << endl;
        while (getline(openData, line, ',')) {
            size_t tab = line.find("\n");
            if (tab != std::string::npos) {
                string string_x_number = line.substr(tab + 1);
                int x = string_to_integer(string_x_number);
                cout << x << endl;
            }
        }
    } else {
        cout << "Can't open file" << endl;
    }

    openData.close();

}


int main() {
    string path = "C:\\Users\\Asus\\CLionProjects\\SwProject\\Data\\data2.csv";
    Value printf;
    try {
        printf.setValueY(path);
        printf.setValueX(path);


    } catch (const system_error &error) {
        std::cerr << "file system error!" << error.what() << '\n';
    } catch (const runtime_error &error) {
        std::cerr << "run time err!" << error.what() << '\n';
    }


    return 0;

}

