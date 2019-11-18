#include "header.h"

int weightBetweenPoints(t_road *roads, int countOfRoads, int index1, int index2) {
    for(int i = 0; i < countOfRoads; i++) {
        if(((roads[i].nbrOfP1 == index1) && (roads[i].nbrOfP2 == index2))
        || ((roads[i].nbrOfP2 == index1) && (roads[i].nbrOfP1 == index2))) {
            return roads[i].weight;
        }
    }
    return 0;
}