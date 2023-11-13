

#include "Memory.h"

ostream &operator << (ostream & out, Memory m) {
    out << m.value;
    return out;
}