//File: A2_S5_20221099_9.cpp
//purpose: Reccursive Bears game
//Author: Abdulrahman Mohammed
//Section: S5
//ID: 20221099
//TA: Eng/Maya
//Date: 5 Nov 2023

#include <bits/stdc++.h>
using namespace std;
bool bears(int n) {
    if (n < 42)
        return false;

    if (n == 42) {
        return true;
    }

    if (n % 2 == 0) {
        if (bears(n / 2)) {
            return true;
        }
    }

    if (n % 3 == 0 || n % 4 == 0) {
        int d1 = n % 10;
        int d2 =  ((n % 100) / 10);
        int multiple = d1 * d2;

        if (bears(n - multiple)) {
            return true;
        }
    }

    if (n % 5 == 0) {
        if (bears(n - 42)) {
            return true;
        }
    }

    return false;
}

int main () {

    bool test1 = bears(250);
    bool test2 = bears(42);
    bool test3 = bears(84);
    bool test4 = bears(53);
    bool test5 = bears(41);

    cout << test1 << endl;
    cout << test2 << endl;
    cout << test3 << endl;
    cout << test4 << endl;
    cout << test5 << endl;


}
