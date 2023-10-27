//File: A2_S5_20221099_6(a).cpp
//purpose: Printing a Number in Binary Using Recursion.
//Author: Abdulrahman Mohammed
//Section: S5
//ID: 20221099
//TA: Eng/Maya
//Date: 27 Oct 2023



#include <bits/stdc++.h>

using namespace std;

void binaryPrint (int n) {
    if (n == 0)
        return;
    binaryPrint(n / 2);
    cout << n % 2;
}




int main () {
    binaryPrint(9);
}
