#include "header.h"

int mx_read_line_(char **lineptr, char delim, const int fd) {
    int status = 0;
    char c = 0;
    int countOfLetters = 0;
    if (fd < 0) return -1;
    
    *lineptr = mx_realloc(*lineptr,1);
    
    while ((status = read(fd, &c, 1)) > 0) {
   
        if ((c == delim) || (status == 0))
           break;
            
        *lineptr = mx_realloc(*lineptr, countOfLetters + 1);
         *(*lineptr + countOfLetters) = c;
        countOfLetters++;
    }
    *(*lineptr + countOfLetters) = 0;
    if(status == 0) return 0;
    return countOfLetters;
}
