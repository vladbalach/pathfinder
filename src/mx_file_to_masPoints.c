#include "header.h"

/*return count of points and write all points to mas consists
  with name of point and nbr*/
int mx_file_to_masPoints(char *name, t_point **points) {

    int     fd      = 0;
    char *  str     = 0;
    int     size    = 0;

    fd = open(name, O_RDONLY);
    *points = mx_realloc(*points,sizeof(t_point) * (size));
    mx_read_line_(&str,'\n',fd);//read first line
    while(mx_read_line_(&str,'-',fd)) {//FIRST POINT
        if(index_of_same_point(size, str, *points) == -1) {
            size++;
            *points =(t_point*)mx_realloc(*points,sizeof(t_point) * (size));
            (*points)[size - 1].name = mx_strdup(str);
            (*points)[size - 1].nbr = size - 1;
            (*points)[size - 1].minDist = 2147483647;
            (*points)[size - 1].minDistFrom = malloc(sizeof(int) * 1);
            *((*points)[size - 1].minDistFrom) = -1;
        }
        mx_read_line_(&str,',',fd);//SECOND POINT
        if(index_of_same_point(size, str, *points) == -1) {
            size++;
            *points =(t_point*)mx_realloc(*points,sizeof(t_point) * (size));
            (*points)[size - 1].name = mx_strdup(str);
            (*points)[size - 1].nbr = size - 1;
            (*points)[size - 1].minDist = 2147483647;
            (*points)[size - 1].minDistFrom = malloc(sizeof(int) * 1);
            *((*points)[size - 1].minDistFrom) = -1;
        }
        mx_read_line_(&str,'\n',fd);
    }
    free(str);
    str = 0;
    return size;
}