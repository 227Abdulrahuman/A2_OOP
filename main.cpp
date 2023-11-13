#include <bits/stdc++.h>
#include "Register.h"
#include "Memory.h"
#include "Operation.h"

using namespace std;

int main () {
    vector<Register> R{16};
    vector<Memory> M{256};
    Operation O;

    //Intializing the addresses
    for (int i = 0; i < 16; i++) {
        R[i].address = i;
    }
    for (int i = 0; i < 256; i++) {
        M[i].address = i;
    }
//***************************************

    M[163].value = "AA";

    O.One(M, R, "4", "A3");
    cout << R[4] << endl;
//********************************
    O.Two(R, "0", "A3");
    cout << R[0] << endl;
//*******************************
    R[O.get_register_by_address(R, "B5")].value = "AB";
    O.Three(R, "B5");
//********************************************************
    R[O.get_register_by_address(R, "A")].value = "55";
    O.Four(R, "A", "4");
    cout << R[4] << endl;
//****************************************************
    string x = O.add_binary("1100", "1100", true);
    cout << x << endl;

//********************
R[2].value = "4A";
R[6].value = "BB";
O.Five(R,"7","2","6");
cout << R[7] <<endl;
}
