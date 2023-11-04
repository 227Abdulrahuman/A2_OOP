//File: A2_S5_20220206_11.cpp
//purpose: File Comparison.
//Author: Abdelmonaem Mahmoud
//Section: S5
//ID: 20220206
//TA: Eng/Maya
//Date: 30 Oct 2023

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void removeSpaces(string word) {
    word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
}

void letters (string f1, string f2)
{
    ifstream file1(f1);
    ifstream file2(f2);
    char char1, char2;
    int linenum=1,charnum=0;
    bool x = false;
    while (file1.get(char1) && file2.get(char2)) {
        charnum++;
        if (char1 != char2) {
            x = true;
            break;
        }
        if (char1 == '\n') {
            linenum++;
            charnum = 0;
        }
    }

    if (x)
    {
        cout<<"Files are different at line number: "<<linenum<<" char number: "<<charnum
            <<"\nfile1: "<<char1<<"\nfile2: "<<char2;
    }
    else{
        cout<<"Files are identical.";
    }
}

void words (string f1, string f2)
{
    ifstream file1(f1);
    ifstream file2(f2);
    string word1,word2;
    int linenum = 1, wordnum = 0;
    bool x = false;

    while (file1 >> word1 && file2 >>word2)
    {
        wordnum++;

        removeSpaces(word1);
        removeSpaces(word2);

        if (word1 != word2)
        {
            x = true;
            break;
        }
        if (word1.find('\n') != string::npos)
        {
            wordnum = 0;
            linenum++;
        }
    }
    if (x)
    {
        cout<< "Files are different at line number: " << linenum <<" word number: "<< wordnum
            << "\nfile1: " <<word1<< "\nfile2: " << word2;
    }
    else
    {
        cout<<"Files are identical.";
    }
}

int main()
{
    string f1,f2;
    cout<<"Enter the initial file name: ";
    getline(cin, f1);
    cout<<"Enter the second file name: ";
    getline(cin, f2);
    int choice;
    cout<<"1. Comparison with letters. \n"
        <<"2. Comparison with words. \n";
    
    cin>>choice;
    if (choice==1)
    {
        letters (f1, f2);
    }
    else if (choice==2)
    {
        words (f1, f2);
    }
    else
    {
        cout<<"Invalid number.";
    }
    return 0;
}