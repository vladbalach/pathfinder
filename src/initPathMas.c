#include "header.h"

void initPathMas(unsigned long long *mainMatrix, t_listOfPaths *listOfPaths, int countPoints, int index) {
    for (int i =0; i < countPoints; i++) {
        listOfPaths->path[i] = *(mainMatrix + index * countPoints + i);
        // if (*(mainMatrix + index * countPoints + i) == MAX_PATH_LENGTH) {
        //     listOfPaths->comeFrom[i] = index;
        // }
    }
    listOfPaths->path[index] = 0;
}
