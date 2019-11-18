#include "header.h"

int index_of_same_point(int size, char*str, t_point *points) {
    for(int i = 0; i < size; i ++) {
            if(mx_strcmp(str, points[i].name) == 0) {
                //printf("NO = %s, index = %d\n", str, i);
                return i;
            }
        }
        return -1;
}
