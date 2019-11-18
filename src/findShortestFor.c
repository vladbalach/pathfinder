#include "header.h"

static void freeP(t_listOfPaths **listOfPaths) {
        while(*listOfPaths) {
        t_listOfPaths *tmp = (*listOfPaths)->next;
        free((*listOfPaths)->comeFrom);
        free((*listOfPaths)->isOnPlace);
        free((*listOfPaths)->path);
        free(*listOfPaths);
        *listOfPaths = tmp;
    }
}

static void freeOutput(t_listOfOutput **outputList) {
        while(*outputList) {
        t_listOfOutput *tmp = (*outputList)->next;
        free((*outputList)->masOfOutput);
        free((*outputList));
        *outputList = tmp;
    }
}

void findShortestFor(t_point *points, t_road *roads, unsigned long long *mainMatrix, int countPoints, int countRoads, int index) {
    t_listOfPaths *listOfPaths = malloc(sizeof(t_listOfPaths));
    t_listOfOutput *outputList = 0;
    listOfPaths->next = NULL;
    listOfPaths->path = malloc(sizeof(unsigned long long) * countPoints);
    listOfPaths->comeFrom = malloc(sizeof(int) * countPoints);
    //0 - not on place; 1 - on place
    listOfPaths->isOnPlace = malloc(sizeof(char) * countPoints);
    initIsOnPlace(listOfPaths->isOnPlace, countPoints, index);
    initComeFrom(listOfPaths->comeFrom, countPoints, index);
    initPathMas(mainMatrix, listOfPaths, countPoints, index);
    find(&outputList, listOfPaths, mainMatrix, countPoints, index);
    reverseList(&outputList);
    sortList(&outputList, countPoints);
    output(index, points, outputList, countPoints, roads, countRoads);
    freeP(&listOfPaths);
    freeOutput(&outputList);
    free(listOfPaths); 
}
