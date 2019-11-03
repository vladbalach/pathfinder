#include "header.h"

bool mx_is_valid_first_line(char *str) {
    int count = 0;
    while(*str) {
        if(!mx_is_digit(*str++))
            return false;
            count++;
    }
    if(count == 0) return false;
    return true;
}