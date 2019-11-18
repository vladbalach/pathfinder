#include "libmx.h"

bool mx_is_digit(char ch) {
    if((ch < 58) && (ch > 47)) 
        return true;
    return false;    
}
