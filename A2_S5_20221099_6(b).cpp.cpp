//File: A2_S5_20221099_6(b).cpp
//purpose: Generating all possible suffix for a binary string.
//Author: Abdulrahman Mohammed
//Section: S5
//ID: 20221099
//TA: Eng/Maya
//Date: 27 Oct 2023

#include <iostream>

using namespace std;

//I have to change the function name, because it gets mixed with a function named numbers in "using namespace std header".

void numbers_generator(string prefix, int k) {
    if (k == 0) {
        cout << prefix << endl;
        return;
    }

    numbers_generator(prefix + "0", k - 1);
    numbers_generator(prefix + "1", k - 1);
}

int main () {
    numbers_generator("00101",2);
}