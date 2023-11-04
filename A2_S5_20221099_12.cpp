//File: A2_S5_20221099_12.cpp
//purpose: Checking for phishing emails.
//Author: Abdulrahman Mohammed
//Section: S5
//ID: 20221099
//TA: Eng/Maya
//Date: 4 Nov 2023
#include <bits/stdc++.h>

using namespace std;

int main () {
    vector<string> words(30) ;words= {"Action required",
                "Alert",
                "Confirm",
                "Dear customer",
                "Document",
                "Financial",
                "Immediately",
                "Important",
                "Information",
                "Link",
                "Login",
                "Notification",
                "Password",
                "Payment",
                "Phishing",
                "Please",
                "Secure",
                "Security",
                "Statement",
                "Urgent",
                "Verify",
                "Warning",
                "Amazon",
                "Apple",
                "Bank of America",
                "Chase",
                "Citibank",
                "eBay",
                "Facebook",
                "Google",
                "IRS",
                "Microsoft",
                "PayPal",
                "Netflix",
                "USPS",
                "Visa"};
    vector<int> count(30,0);
    vector<int>score(30);

    for(int i = 0; i < 30;i++) {
        if (i < 10) score[i] = 1;
        else if (i < 20)   score[i] = 2;
        else score[i] = 3;
    }

   fstream file("input.txt");
   string line;
   //Take each line from the file and put it in var line
    while (getline(file,line)) {
        for (int i = 0; i < 30; i++) {

            while (line.find(words[i]) != string::npos) {
                count[i]++;
                //make the line equal to the rest of the line after the position that it found the word in.
                line.erase(0, line.find(words[i]) + words[i].length());
            }
        }
    }
    file.close();

    //Output

    for(int i = 0; i < 30; i++) {
        cout << "The number of occurrences for  " <<    words[i] << " = " << count[i] <<" and the total points = " << score[i] * count[i] << endl;
    }
    return 0;
}
