//File: A2_S5_20221099_3.cpp
//purpose: To put write spaces and to caplitalize first character
//Author: Remon raafat nassif
//Section: S5
//ID: 20220139
//TA: Eng/Maya
//Date: 27 Oct 2023
#include <iostream>
#include <string>
using namespace std;
void Q_1()
{
    string sentence[100];
    for (int i = 0; i < 100; i++) {
        string x;
        cin >> x;
        if (x[x.size() - 1] == '.') {
            sentence[i] = x;
            break;
        }
        else {
            sentence[i] = x;
        }
    }
    sentence[0][0] = toupper(sentence[0][0]);
    for (int i = 1; i < sentence[0].size(); i++) {
        sentence[0][i] = tolower(sentence[0][i]);
    }

    for (int i = 1; i < 100; i++) {
        if (sentence[i].empty()) {
            break;
        }
        for (int j = 0; j < sentence[i].size(); j++) {
            sentence[i][j] = tolower(sentence[i][j]);
        }
    }

    for (int i = 0; i < 100; i++) {
        if (sentence[i].empty()) {
            break;
        }
        cout << sentence[i] << " ";
    }
}
int main() {

    Q_1();


    return 0;
}