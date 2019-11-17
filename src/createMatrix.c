#include "header.h"

unsigned long long* createMatrix(t_point *points, t_road *roads, int countRoads, int countPoints) {
    //CREATE MAIN MATRIX
    unsigned long long *matrix = (unsigned long long*) malloc (sizeof(unsigned long long) * countPoints * countPoints);
    for(int i = 0; i < countPoints * countPoints; i++) {
        *(matrix + i) = MAX_PATH_LENGTH;
    }
    for(int i = 0; i < countRoads; i++) {
        *(matrix + roads[i].nbrOfP1 * countPoints + roads[i].nbrOfP2) = roads[i].weight;
        *(matrix + roads[i].nbrOfP2 * countPoints + roads[i].nbrOfP1) = roads[i].weight;
    }
    return matrix;
}
