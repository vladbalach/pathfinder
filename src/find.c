#include "header.h"

static void freePath(t_listOfPaths **list) {
        free((*list)->path);
        free((*list)->isOnPlace);
        free((*list)->comeFrom);
        free(*list);
}

static void allocateMemory(t_listOfPaths *list, int countPoints) {
    list->next = NULL;
    list->path = malloc(sizeof(unsigned long long) * countPoints);
    list->comeFrom = malloc(sizeof(int) * countPoints);
    //0 - not on place; 1 - on place
    list->isOnPlace = malloc(sizeof(char) * countPoints);
}

void find(t_listOfOutput **listOfOutput, t_listOfPaths *listOfPaths, 
    unsigned long long *mainMatrix, int countPoints, int index) {
    t_listOfPaths *newList = malloc(sizeof(t_listOfPaths));
    int minIndex = 0;
    allocateMemory(newList, countPoints);
    while(minIndex != -1) {
        minIndex = findMin(listOfPaths, countPoints);
        if(minIndex != -1) {
            listOfPaths->isOnPlace[minIndex] = 1;
            for(int i = 0; i < countPoints; i++) {
                if(*(mainMatrix + countPoints * minIndex + i) < MAX_PATH_LENGTH) {
                    if(listOfPaths->path[i] > listOfPaths->path[minIndex] 
                    + *(mainMatrix + countPoints * minIndex + i)) {
                        listOfPaths->path[i] = listOfPaths->path[minIndex] 
                        + *(mainMatrix + countPoints * minIndex + i);
                        listOfPaths->comeFrom[i] = minIndex;
                    } 
                    else if(listOfPaths->path[i] == listOfPaths->path[minIndex] 
                    + *(mainMatrix + countPoints * minIndex + i)) {
                        cpyStructure(listOfPaths, newList, countPoints);
                        listOfPaths->comeFrom[i] = minIndex;
                        find(listOfOutput, newList, mainMatrix, countPoints, index);
                    }
                }
            }
        }
    }
    fillListOfOutput(listOfOutput, listOfPaths, countPoints, index);
    freePath(&newList);
}
