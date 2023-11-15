#include<iostream>
#include<string>
using namespace std;

string addBinary(string binary1, string binary2) {
    string result = "";
    int carry = 0;

    if (binary1.length() < binary2.length()) {
        binary1 = string(binary2.length() - binary1.length(), '0') + binary1;
    }
    else if (binary2.length() < binary1.length()) {
        binary2 = string(binary1.length() - binary2.length(), '0') + binary2;
    }

    for (int i = binary1.length() - 1; i >= 0; i--) {
        int bit1 = binary1[i] - '0';
        int bit2 = binary2[i] - '0';

        int sum = (bit1 + bit2 + carry) % 2;
        carry = (bit1 + bit2 + carry) / 2;

        result = char(sum + '0') + result;
    }

    if (carry) {
        result = '1' + result;
    }
    // to remove left zeros if nessessory
    string result2 = "";
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != '0')
        {
            for (int j = i; j < result.size(); j++)
            {
                result2 += result[j];
            }
            break;
        }
    }

    return result2;
}
int main()
{
    string s = "00011111";
    string s2 = "0010101010";
    string sum = addBinary(s, s2);
    cout << sum << endl;

    return 0;
}
