#include "header.h"

char *indexToNameOfPoint(t_point *points, int countOfPoints, int index) {
    for(int i = 0; i < countOfPoints; i++) {
        if((*(points + i)).nbr == index) {
            return (*(points + i)).name;
        }
    }
    return NULL;
}
