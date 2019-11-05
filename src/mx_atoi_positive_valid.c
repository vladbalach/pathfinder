#include "header.h"

int mx_atoi_positive_valid(char *str) {
    int len = mx_strlen(str);
    int sum = 0;
    int nmbr = 0;
    int pow = 0;
    for(int i = len - 1; i >= 0; i--) {
        nmbr = str[i] - '0';
        for(int j = 0; j < pow; j++) {
            nmbr *= 10;
        } 
        pow++;
        sum += nmbr;
    }
    return sum;
}
