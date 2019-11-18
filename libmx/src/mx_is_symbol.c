#include "libmx.h"

bool mx_is_symbol(char ch) {
    if (((ch < 91) && (ch > 64)) || ((ch < 123) && (ch > 96)))
        return true;

    return false;
}
