#include "header.h"

//return index of point gets that name
int indexOfPoint(t_point **points, char * str, int count) {
    for(int i = 0; i < count; i++) {
        if(mx_strcmp((*points)[i].name,str) == 0) {
            return (*points)[i].nbr;
        }
    }
    return -1;
}
