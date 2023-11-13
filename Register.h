
#ifndef PYTHON_REGISTER_H
#define PYTHON_REGISTER_H
#include <bits/stdc++.h>

using namespace std;


class Register {
public:
    int address;
    string value = "00";
    friend ostream &operator << (ostream &out, Register r);
};


#endif
