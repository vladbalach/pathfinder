#include "header.h"

void cpyStructure(t_listOfPaths *oldNode, t_listOfPaths *newNode, int countPoints) {
    for(int i = 0; i < countPoints; i++) {
        newNode->comeFrom[i] = oldNode->comeFrom[i];
        newNode->isOnPlace[i] = oldNode->isOnPlace[i];
        newNode->path[i] = oldNode->path[i];
    }
}