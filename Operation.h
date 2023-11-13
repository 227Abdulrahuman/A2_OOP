

#ifndef PYTHON_OPERATION_H
#define PYTHON_OPERATION_H
#include <bits/stdc++.h>
#include "Register.h"
#include "Memory.h"
using namespace std;

class Operation {
public:


    int hex_to_int(string hex_string);
    string hex_to_bin(string hex_string);
    //Retrun a memory by recieving its address
    int get_memory_by_address(vector<Memory>& m,string address);
    //Return a register by recieving its acdess
    int get_register_by_address(vector<Register> &R, string address);

    //Load the register R with the bit pattern found in memory whose address is XY (1RXY)
   void One(vector<Memory>& M, vector<Register> &R, string reg_add, string mem_address);
   //Load the register R with the bit pattern XY (2RXY)
   void Two(vector<Register>&R,string add, string value);
   //Print the value in R to the scree
   void Three(vector<Register>&R, string add);
   //Copy the bit pattern found in R to S
   void Four(vector<Register>&R, string add1, string add2);
   //Adding two binary numbers, if set to 1 we ignore the carry
    string add_binary(string one, string two, bool flag);
    //Convert 2's comp neg to pos
    string negative_to_positive(string neg);

    //Add the bits in S and in T and leave the result in R
    void Five(vector<Register> &R,string place_add,string add_1, string add_2 );
};


#endif
