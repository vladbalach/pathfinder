#include "libmx.h"

// static int strncmp(char* s1, char* s2, int n) {
//     for (int i = 0; i < n; i++) {
//         if (s1[i] != s2[i]) return 0;//NOT EQUAL
//     }
// }

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if ((str == 0) || (sub == 0) || (replace == 0)) return 0;

    int lenSub = mx_strlen(sub);
    int countSubstr = 0;
    int startI = mx_get_substr_index(str, sub);
    int endI = startI + lenSub;
    char *newStr = 0;
    char *tmp = 0;

    newStr =  mx_strdup(str);
    if(startI <= 0) 
        return newStr;
    while (mx_get_substr_index(newStr, sub) > 0) {
        startI = mx_get_substr_index(newStr, sub);
        endI = startI + lenSub;
        tmp = malloc (mx_strlen(str) + (mx_strlen(replace) - mx_strlen(sub)) + 1);
        mx_strncpy(tmp, newStr, startI);
        mx_strcpy(&tmp[startI], replace);
        mx_strcpy(&tmp[startI + mx_strlen(replace)], &newStr[endI]);
        free(newStr);
        newStr = tmp;
        countSubstr++;
    }
    newStr[mx_strlen(str) + countSubstr * (mx_strlen(replace) - mx_strlen(sub))] = 0;
    return newStr;
}
