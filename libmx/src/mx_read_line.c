#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, int delim, const int fd) {
    int status = 0;
    int c = 0;
    int countOfLetters = 0;
    if ((lineptr == 0) || (fd < 0)) return -1;
    while ((status = read(fd, &c, 1)) > 0) {
        if ((c == delim) || (status == 0))
           break;
        *lineptr = mx_realloc(*lineptr, countOfLetters + 1);
         *(*lineptr + countOfLetters) = c;
        countOfLetters++;
    }
    *(*lineptr + countOfLetters) = 0;
    if (countOfLetters < buf_size) {
        *lineptr = mx_realloc(*lineptr, 1);
        **lineptr = 0;
    }
    if(status == 0) return 0;
    return countOfLetters;
}
