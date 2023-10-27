//File: A2_S5_20221099_3.cpp
//purpose: Splitting a string based on a delimiter.
//Author: Abdulrahman Mohammed
//Section: S5
//ID: 20221099
//TA: Eng/Maya
//Date: 27 Oct 2023



#include <bits/stdc++.h>

using namespace std;




vector<string> split(string target, string delimiter) {
// We simply search for the del, push the string before it, then erase it, repeat !!!
    vector<string> answer;

    int del_index = 0;

    while ((del_index = target.find(delimiter)) != string::npos) {
        answer.push_back(target.substr(0,del_index));
        target.erase(0, del_index + delimiter.length());
    }

    if (!target.empty())
        answer.push_back(target);


    return answer;
}


int main () {

vector<string> x = split("10,20,30", ",");

for (auto & i : x)
    cout << i << ' ';

}
