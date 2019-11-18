#include "header.h"

void validation(int argc, char *argv[]) {
    int count = 1;
     if(argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    
    int fd = open(argv[1], O_RDONLY);
    if(fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" doesn't exist\n");
        exit(1);
    }
    if(mx_is_file_empty(argv[1])) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
    char* str = 0; 
    mx_read_line_(&str, '\n', fd);
    if(!mx_is_valid_first_line(str)) {
        mx_printerr("error: line 1 isn't valid\n");
        free(str);
        exit(1);
    }
    
        while(mx_read_line_(&str, '\n', fd)) {
        count++;
        if(!mx_is_valid_string(str)) {//valid string A-B,0
            mx_printerr("error: line ");
            char *s = mx_itoa(count);
            mx_printerr(s);
            mx_printerr(" isn't valid\n");
            free(str);
            free(s);
            exit(1);
        }
    }
    free(str);
    close(fd);
    return;
}
