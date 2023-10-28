//File: A2_S5_20220206_2.cpp
//purpose: convert male speech to inclusive speech that includes both male and female.
//Author: Abdelmonaem Mahmoud Abdelmonaem Ahmed
//Section: S5
//ID: 20220206
//TA: Eng/Maya
//Date: 27 Oct 2023


#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout<<"Enter a sentence:\n";
    getline(cin, s);

    for (int i = 2; i < s.size(); i++) {
        if ((s[i - 2] == 'h' || s[i - 2] == 'H') && s[i - 1] == 'e' && !isalpha(s[i])) {
            s.replace(i - 2, 2, (s[i - 2] == 'h') ? "he or she" : "He or She");
            i += 9;
        }
    }

    for (int i = 3; i < s.size(); i++) {
        if ((s[i - 3] == 'h' || s[i - 3] == 'H') && s[i - 2] == 'i' && s[i - 1] == 'm' && !isalpha(s[i])) {
            s.replace(i - 3, 3, (s[i - 3] == 'h') ? "him or her" : "Him or Her");
            i += 10;
        }
    }

    cout <<"Converted sentence:\n"
         <<s;
    return 0;
}