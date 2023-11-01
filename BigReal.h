
#ifndef UNTITLED1_BIGREAL_H
#define UNTITLED1_BIGREAL_H

#include <bits/stdc++.h>

using namespace std;



class BigReal {


    int decimal_point_index;
    char sign;
    string num ;
    bool isValid(string input);
    void assignNum(string Realnum);


public:
    void get();
    friend ostream &operator << (ostream &out, BigReal Realnum);

    long long get_size();
    bool get_sign();

    bool operator == (const BigReal& Realnum);
    bool operator < (const BigReal& Realnum);
    bool operator > (const BigReal& Realnum);


    BigReal operator - (BigReal Realnum);
    BigReal operator + (BigReal Realnum);
    BigReal operator = (BigReal Realnum);


    //Intitalizing a default constructor and a paramiterized one

    BigReal(){}
    BigReal(string Realnum) {
        isValid(Realnum);
    }
};



#endif //UNTITLED1_BIGREAL_H
