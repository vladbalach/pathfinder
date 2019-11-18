#include "header.h"

//transform strings roads to struct road
int mx_file_to_masRoads(char *name, t_road **roads, t_point **points, int count) {
    int     fd      = 0;
    char *  str     = 0;
    int     size    = 0;
    int index1 = 0;
    int index2 = 0;
    int weight = 0;
    fd = open(name, O_RDONLY);
    *roads = mx_realloc(*roads,sizeof(t_road) * (size));
    mx_read_line_(&str,'\n',fd);//read first line
    while(mx_read_line_(&str,'-',fd)) {//FIRST POINT
        index1 = indexOfPoint(points, str, count);
        mx_read_line_(&str,',',fd);//SECOND POINT
        index2 = indexOfPoint(points, str, count);
        mx_read_line_(&str,'\n',fd);
        weight = mx_atoi_positive_valid(str);
        //CREATE THE ROAD
        if(!haveRoad(index1, index2, weight, roads, size)) {//if have not road
            size++;
            *roads =(t_road*)mx_realloc(*roads,sizeof(t_road) * (size));
            (*roads)[size - 1].nbrOfP1 = index1;
            (*roads)[size - 1].nbrOfP2 = index2;
            (*roads)[size - 1].weight = weight;
        }
    }
    free(str);
    str = 0;
    return size;
} 
