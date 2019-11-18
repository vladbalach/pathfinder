#include "header.h"

t_listOfOutput *createNode(int *data) {
    t_listOfOutput *newNode = (t_listOfOutput*) malloc (sizeof(t_listOfOutput));
    newNode->masOfOutput = data;
    newNode->next = 0;
    return newNode;
}

void pushBack(t_listOfOutput **list, int *data) {
    t_listOfOutput *newNode = createNode(data);
    t_listOfOutput *tmp = *list;
    if (*list == 0) {
        *list = newNode;
    }
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = newNode;
    }
}

bool isDuplicate(t_listOfOutput *listOfOutput, int *mas, int countPoints) {
    t_listOfOutput *tmp = listOfOutput;
    while(tmp) {
        bool isDuplicate = true;
        for(int i = 0; i < countPoints; i++) {
            if (mas[i] != tmp->masOfOutput[i]) {
                isDuplicate = false;
                break;
            }
        }
        if(isDuplicate) return true;
        tmp = tmp->next;
    }
    return false;
}

void fillListOfOutput(t_listOfOutput **listOfOutput, t_listOfPaths *listOfPaths, int countPoints, int index) {

    int currentIndex = 0;
    for (int i = index + 1; i < countPoints; i++) {
        int *tmpMas = malloc(sizeof(int) * (countPoints + 1));
        for(int k = 0; k < countPoints+1; k++) {
            tmpMas[k] = -1;
        }
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
        if(isDuplicate(*listOfOutput, tmpMas, countPoints)) {
            free(tmpMas);
        } 
        else
            pushBack(listOfOutput, tmpMas);
        //free(tmpMas);
    }
}



void find(t_listOfOutput **listOfOutput, t_listOfPaths *listOfPaths, unsigned long long *mainMatrix, int countPoints, int index) {
   
    int minIndex = 0;
    while(minIndex != -1) {
        minIndex = findMin(listOfPaths, countPoints);
        //printf("minIndex = %d\n", minIndex);
        if(minIndex != -1) {
            listOfPaths->isOnPlace[minIndex] = 1;
            //listOfPaths->comeFrom[]
            for(int i = 0; i < countPoints; i++) {
                if(*(mainMatrix + countPoints * minIndex + i) < MAX_PATH_LENGTH) {
                    if(listOfPaths->path[i] > listOfPaths->path[minIndex] 
                    + *(mainMatrix + countPoints * minIndex + i)) {
                        listOfPaths->path[i] = listOfPaths->path[minIndex] 
                        + *(mainMatrix + countPoints * minIndex + i);
                        listOfPaths->comeFrom[i] = minIndex;
                    } 
                    else
                    //IF ==
                    if(listOfPaths->path[i] == listOfPaths->path[minIndex] 
                    + *(mainMatrix + countPoints * minIndex + i)) {
                        //printf("RECURSION\n");
                        listOfPaths->next = malloc(sizeof(t_listOfPaths));
                        listOfPaths->next->next = NULL;
                        listOfPaths->next->path = malloc(sizeof(unsigned long long) * countPoints);
                        listOfPaths->next->comeFrom = malloc(sizeof(int) * countPoints);
                        //0 - not on place; 1 - on place
                        listOfPaths->next->isOnPlace = malloc(sizeof(char) * countPoints);
                        cpyStructure(listOfPaths, listOfPaths->next, countPoints);
                        listOfPaths->comeFrom[i] = minIndex;
                        //t_listOfPaths *tmp = list 
                        //find(listOfOutput, listOfPaths->next, mainMatrix, countPoints, index);

                        //free(listOfPaths->next);
                    }
                }
            }
        }
    }
    
     
        fillListOfOutput(listOfOutput, listOfPaths, countPoints, index);
        // while(listOfPaths) {
        //     t_listOfPaths *tmp = listOfPaths->next;
        //     free(listOfPaths->path);
        //     free(listOfPaths->isOnPlace);
        //     free(listOfPaths->comeFrom);
        //     free(listOfPaths);
        //     listOfPaths = tmp;
        // }
}