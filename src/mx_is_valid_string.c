#include "header.h"

//return true is string a valid and false otherwise
bool mx_is_valid_string(char* str) {
    bool isMoreZero = false;
    if ((mx_count_char(str,'-') != 1) 
    || (mx_count_char(str,',') != 1))
        return false;
    //TO '-'

    while( *str) {
        if(*str == '-') {
             str++;
             break;
        }
        if (!mx_is_symbol(*str))
            return false;
        isMoreZero = true;
        str++;
    }
    if(!isMoreZero) return false;
    isMoreZero = false;
    //TO ','
    while( *str) {
        if(*str == ',') {
             str++;
             break;
        }
        if (!mx_is_symbol(*str))
            return false;     
        isMoreZero = true;
        str++;
    }
    if(!isMoreZero) return false;
    isMoreZero = false;
    //AFTER ','
    while( *str) {
        if(!mx_is_digit(*str++)) return false;
        isMoreZero = true;
    }
    if(!isMoreZero) return false;
    return true;
}
