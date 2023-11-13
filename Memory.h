
#ifndef PYTHON_MEMORY_H
#define PYTHON_MEMORY_H

#include <bits/stdc++.h>

using namespace std;

class Memory {

public:
    int address;
    string value = "00";
    //Making it as friend just in case I added private memebers
   friend ostream &operator << (ostream &out, Memory m);
};


#endif
