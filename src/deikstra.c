#include "header.h"

void deikstra(t_point *points, t_road *roads, int countRoads, int countPoints) {
    unsigned long long *mainMatrix = createMatrix(points, roads, countRoads, countPoints);
   //for (int i = 0; i < countPoints-1; i++) 
        findShortestFor(points, roads,  mainMatrix, countPoints, countRoads, 0);
    free(mainMatrix);
}