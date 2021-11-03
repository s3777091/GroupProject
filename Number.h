//
// Created by Asus on 11/3/2021.
//

#ifndef MAIN_CPP_NUMBER_H
#define MAIN_CPP_NUMBER_H


class Number {
    int x;
    int y;
public:
    int getX() const {
        return x;
    }

    void setX(int x) {
        Number::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Number::y = y;
    }
};


#endif //MAIN_CPP_NUMBER_H
