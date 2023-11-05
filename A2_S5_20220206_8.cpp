//File: A2_S5_20220206_8.cpp
//purpose: A Fractal Pattern.
//Author: Abdelmonaem Mahmoud
//Section: S5
//ID: 20220206
//TA: Eng/Maya
//Date: 4 Oct 2023

#include <iostream>

using namespace std;

void printSpaces(int i) {
    for (int j = 0; j < i; j++) {
        cout << "  ";
    }
}

void printStars(int n) {
    for (int i = 0; i < n; i++) {
        cout << "* ";
    }
}

void pattern(int n, int i) {
    if (n == 1) {  // base case
        printSpaces(i);
        printStars(n);
        cout<<endl;
        return;
    }
    pattern(n / 2, i);  // top half

    printSpaces(i);
    printStars(n);
    cout << endl;

    pattern(n / 2, i + n / 2); // bottom half
}

int main() {
    int n,i;
    cin >> n >> i;
    pattern(n, i);
    return 0;
}