#include "header.h"

void fillListOfOutput(t_listOfOutput **listOfOutput, t_listOfPaths *listOfPaths, int countPoints, int index) {
    int currentIndex = 0;
    for (int i = index + 1; i < countPoints; i++) {
        int *tmpMas = malloc(sizeof(int) * (countPoints + 1));
        for(int k = 0; k < countPoints+1; k++)
            tmpMas[k] = -1;
        currentIndex = i;
        tmpMas[0] = currentIndex;
        int j = 1;
        while((listOfPaths->comeFrom[currentIndex] != index) 
        &&  (listOfPaths->comeFrom[currentIndex] != -1)) {
            currentIndex = listOfPaths->comeFrom[currentIndex];
            tmpMas[j] = currentIndex;
            j++;
        }
        tmpMas[j] = index;
        if(isDuplicate(*listOfOutput, tmpMas, countPoints))
            free(tmpMas);
        else
            pushBack(listOfOutput, tmpMas);
    }
}
