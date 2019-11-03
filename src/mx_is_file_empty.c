#include "header.h"

bool mx_is_file_empty(char* name) {
    int fd = open(name, O_RDONLY);
    
    if(fd < 0) return -1;
    char ch = 0;
    if(read(fd,&ch,1) == 0) {
        close(fd);
        return true;
    }
    close(fd);
    return false;
}
