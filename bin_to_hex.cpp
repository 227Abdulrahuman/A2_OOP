#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

string decToHex(int decimal) {
    string hex = "";
    while (decimal > 0) {
        int remainder = decimal % 16;
        char hexDigit = '0';
        if (remainder >= 0 && remainder <= 9) {
            hexDigit = '0' + remainder;
        }
        else {
            hexDigit = 'A' + remainder - 10;
        }
        hex += hexDigit;
        decimal /= 16;
    }
    reverse(hex.begin(), hex.end());
    return hex;
}
string Bin_To_Hex(string bin)
{
    int decimal = 0;
    int base = 1;

    for (int i = bin.length() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            decimal += base;
        }

        base *= 2;
    }
    int intbin = stoi(bin, nullptr);
    return decToHex(intbin);

}
int main()
{
    string s = "00011111";
    cout << Bin_To_Hex(s);
    return 0;
}
