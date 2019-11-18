#include "header.h"

void validation(int argc, char *argv[]) {
    int status = 0;
    int count = 1;
     if(argc != 2) {
        mx_printstr("usage: ./pathfinder [filename]");
        exit(1);
    }
    
    int fd = open(argv[1], O_RDONLY);
    if(fd < 0) {
        mx_printstr("error: file ");
        mx_printstr(argv[1]);
        mx_printstr(" doesn't exist");
        exit(1);
    }
    if(mx_is_file_empty(argv[1])) {
        mx_printstr("error: file ");
        mx_printstr(argv[1]);
        mx_printstr(" is empty");
        exit(1);
    }
    char* str = 0; 
    mx_read_line_(&str, '\n', fd);
    if(!mx_is_valid_first_line(str)) {
        mx_printstr("error: line 1 isn't valid");
        free(str);
        exit(1);
    }
    
        while(mx_read_line_(&str, '\n', fd)) {
        count++;
        if(!mx_is_valid_string(str)) {//valid string A-B,0
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(count));
            mx_printerr(" isn't valid");
            free(str);
            exit(1);
        }
    }
    free(str);
    close(fd);
    return;
}
