#include "BigReal.h"

bool BigReal::isValid(string input) {

  if (input[0] == '+' or input[0] == '-') {
      sign = input[0];
      input.erase(0,1);
  } else
      sign = '+';
  bool Has_Decimal {0};
  num = input;
  for (long long i = 0; i < input.size();i++) {
      if (input[i] == '.') {
          if (!Has_Decimal)    { Has_Decimal = true; decimal_point_index = i;}
          else if (Has_Decimal) {
              return false;
          }
      }
      if ((input[i] < 48 or input[i] > 57) and input[i] != '.' )
          return 0;
  }
    return true;
}




// Overloading the less than Operator (<).

bool BigReal ::operator < (const BigReal &Realnum) {
    string small=""; string big="";
    long long lsmall = num.length(); long long lbig = Realnum.num.length();

    //Puting zeros on the left in case of unmatching sizes
    while (lbig > lsmall) {
        small += '0';
        lsmall++;
    }

    while (lsmall > lbig) {
        big += '0';
        lbig++;
    }
    small += num;
    big += Realnum.num;


    if(sign == '-' and Realnum.sign == '+')
        return true;
    else if (sign == '+' and Realnum.sign == '-')
        return false;
    else if (sign == '+' and Realnum.sign == '+')
        return small < big;
    else if (sign == '-' and Realnum.sign == '-')
        return small > big;

}


//Overloading the greater than operator (>).

bool BigReal::operator>(const BigReal &Realnum) {
    string small=""; string big="";
    long long lbig = num.length(); long long lsmall = Realnum.num.length();

    //Puting zeros on the left in case of unmatching sizes
    while (lbig > lsmall) {
        small += '0';
        lsmall++;
    }

    while (lsmall > lbig) {
        big += '0';
        lbig++;
    }
    big += num;
    small += Realnum.num;


    if(sign == '-' and Realnum.sign == '+')
        return false;
    else if (sign == '+' and Realnum.sign == '-')
        return true;
    else if (sign == '+' and Realnum.sign == '+')
        return big > small;
    else if (sign == '-' and Realnum.sign == '-')
        return small > big;
}

//Overloading the equal Operator (==).

bool BigReal::operator==(const BigReal &Realnum) {
    if(sign == Realnum.sign and num == Realnum.num)
        return true;
    else
        return false;
}

//Overloading the assignment operator (=).
BigReal BigReal::operator=(BigReal Realnum) {
    sign = Realnum.sign;
    num = Realnum.num;
    //Return what is inside the pointer pointing to this obj which is the obj.
    return *this;
}

//Overloading the addition operation (+).

BigReal BigReal::operator+(BigReal Realnum) {
    if (Realnum.sign == sign) {
        BigReal answer;
        answer.num = "";
        answer.sign = sign;
        string Before_original = "", After_original = "", Before_input = "", After_input = "";

        bool check_point{0};

        for (int i = 0; i < num.size(); i++) {
            if (num[i] == '.') {
                check_point = 1;
                continue;
            }
            if (!check_point)
                Before_original += num[i];
            else
                After_original += num[i];
        }
        check_point = 0;
        for (int i = 0; i < Realnum.num.size(); i++) {
            if (Realnum.num[i] == '.') {
                check_point = true;
                continue;
            }
            if (!check_point)
                Before_input += Realnum.num[i];
            else
                After_input += Realnum.num[i];
        }

        //Filling the zeros
        while (Before_original.size() < Before_input.size()) Before_original = '0' + Before_original;
        while (Before_original.size() > Before_input.size()) Before_input = '0' + Before_input;
        while (After_original.size() < After_input.size()) After_original = After_original + '0';
        while (After_original.size() > After_input.size()) After_input = After_input + '0';
        //adding The after
        int carry = 0;

        for (int i = After_input.size() - 1; i >= 0; i--) {
            answer.num = ((char) (((After_input[i] - '0' + After_original[i] - '0' + carry) % 10) + '0')) + answer.num;
            carry = (After_input[i] - '0' + After_original[i] - '0' + carry) / 10;
        }

        answer.num = '.' + answer.num;

        for (int i = Before_input.size() - 1; i >= 0; i--) {
            answer.num =
                    ((char) (((Before_input[i] - '0' + Before_original[i] - '0' + carry) % 10) + '0')) + answer.num;
            carry = (Before_input[i] - '0' + Before_original[i] - '0' + carry) / 10;
        }

        if (carry != 0) {
            answer.num = (char) (carry + '0') + answer.num;
        }
        //Debugging . at the end
        if (answer.num.back() == '.') answer.num.pop_back();


        return answer;
    }
    else {
        // We Will Change The sign because the (-) operator changes the sign of the input
        if (Realnum.sign == '+')    Realnum.sign = '-';
        else    Realnum.sign = '+';
        return BigReal::operator-(Realnum);
    }
}
BigReal BigReal::operator-(BigReal Realnum) {

    if (Realnum.sign == '-')    Realnum.sign = '+';
    else Realnum.sign = '-';

    if (sign == Realnum.sign) {
        return BigReal::operator+(Realnum);

    }

    BigReal answer;
    answer.num = "";
    answer.sign = sign;
    string Before_original="", After_original="", Before_input="",After_input="";

    bool check_point{0};

    for(int i = 0; i < num.size(); i++) {
        if (num[i] == '.') {
            check_point = 1;
            continue;
        }
        if (!check_point)
            Before_original += num[i];
        else
            After_original += num[i];
    }
    check_point = 0;
    for (int i = 0; i < Realnum.num.size(); i++) {
        if (Realnum.num[i] == '.') {
            check_point = true;
            continue;
        }
        if (!check_point)
            Before_input += Realnum.num[i];
        else
            After_input += Realnum.num[i];
    }

    //Filling the zeros
    while (Before_original.size() < Before_input.size()) Before_original = '0' + Before_original;
    while (Before_original.size() > Before_input.size()) Before_input = '0' + Before_input;
    while (After_original.size() < After_input.size()) After_original = After_original + '0';
    while (After_original.size() > After_input.size()) After_input = After_input + '0';

    string original = Before_original + After_original; string input = Before_input + After_input;
    string Bigger,Smaller;
    if (original > input) Bigger = original, Smaller = input, answer.sign = sign;
    else if (original < input)  Smaller = original, Bigger = input, answer.sign = Realnum.sign;
    else {
        answer.num = "0";
        answer.sign = '+';
        return answer;
    }
    for (int i = Bigger.size() -  1; i >= 0; i--) {
        if (Bigger[i] < Smaller[i]) {
            int index = i -1;
            while (Bigger[index] == '0') {
                Bigger[index] = '9';
                index--;
            }
            //Borrwing
            Bigger[index]--;
            //Subtracting
            answer.num = (char) ((((10 + Bigger[i] - '0') - (Smaller[i] - '0'))) + '0') + answer.num;
            //Locating decimal point
            if (Bigger.size() - i == After_input.size()) {
                answer.num = '.' + answer.num;
            }
        } else {
            answer.num = (char) ((((Bigger[i] - '0') - (Smaller[i] - '0'))) + '0') + answer.num;
            if (Bigger.size() - i == After_input.size()) {
                answer.num = '.' + answer.num;
            }
        }
    }
    return answer;
}
bool BigReal::get_sign() {
    if (sign == '+')
        return 1;
    else
        return 0;
}

long long BigReal ::get_size() {
    return num.size();
}


//Overloading the Output function

ostream &operator << (ostream &out, BigReal number) {
    if (number.sign == '+') out << number.num << endl;
    else
        out << number.sign << number.num << endl;
    return out;
}

void BigReal ::get() {
    cout << num << endl;
}