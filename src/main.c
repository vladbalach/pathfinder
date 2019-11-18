#include "header.h"

static void freePoints(t_point* points, int countPoints) {
    for(int i = 0; i < countPoints; i++) {
        free(points[i].name);
        free(points[i].minDistFrom);
    }
    free(points);
}

int main(int argc, char *argv[]) {
    validation(argc,argv);
    t_point *points;
    t_road *roads;
    int countRoads = 0;
    //Write all nodes to mas name - nbr
    int countPoints = mx_file_to_masPoints(argv[1], &points);
    int fd = open(argv[1], O_RDONLY);
    char *str = 0;
    mx_read_line_(&str,'\n',fd);//read first line
    if(mx_atoi_positive_valid(str) != countPoints) {
        mx_printerr("error: invalid number of islands\n");
        freePoints(points, countPoints);
        exit(1);
    }
    free(str);
    //transform file to mas Roads
    countRoads = mx_file_to_masRoads(argv[1], &roads, &points, countPoints);
    freePoints(points, countPoints);
    free(roads);
    return 0;
}
