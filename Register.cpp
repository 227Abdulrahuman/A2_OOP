#include "Register.h"


ostream &operator << (ostream & out, Register r) {
    out << r.value;
    return out;
}