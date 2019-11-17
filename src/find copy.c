// #include "header.h"

// void find(t_listOfPaths *listOfPaths, unsigned long long *mainMatrix, int countPoints, int index) {
//     int minIndex = 0;
//     int comeFrom = malloc (sizeof(int) * countPoints);
//     initComeFrom(comeFrom,countPoints, index);
//     while(minIndex != -1) {
//         minIndex = findMin(listOfPaths, countPoints);
//         //printf("minIndex = %d\n", minIndex);
//         if(minIndex != -1) {
//             listOfPaths->isOnPlace[minIndex] = 1;
//             //listOfPaths->comeFrom[]
//             for(int i = 0; i < countPoints; i++) {
//                 if(*(mainMatrix + countPoints * minIndex + i) < MAX_PATH_LENGTH) {
//                     if(listOfPaths->path[i] > listOfPaths->path[minIndex] 
//                     + *(mainMatrix + countPoints * minIndex + i)) {
//                         listOfPaths->path[i] = listOfPaths->path[minIndex] 
//                         + *(mainMatrix + countPoints * minIndex + i);
//                         listOfPaths->comeFrom[i] = minIndex;
//                     } 
//                     else
//                     //IF ==
//                     if(listOfPaths->path[i] == listOfPaths->path[minIndex] 
//                     + *(mainMatrix + countPoints * minIndex + i)) {
//                         //printf("RECURSION\n");
//                         listOfPaths->next = malloc (sizeof(t_listOfPaths));
//                         listOfPaths->next->next = NULL;
//                         listOfPaths->next->path = malloc(sizeof(unsigned long long) * countPoints);
//                         listOfPaths->next->comeFrom = malloc(sizeof(int) * countPoints);
//                         //0 - not on place; 1 - on place
//                         listOfPaths->next->isOnPlace = malloc(sizeof(char) * countPoints);
//                         cpyStructure(listOfPaths, listOfPaths->next, countPoints);
//                         listOfPaths->comeFrom[i] = minIndex;
//                         find(listOfPaths->next, mainMatrix, countPoints, index);
//                     }
//                 }
//             }
//         }
//     }
//     printf("INDEX = %d: ", index);
//     for(int i = 0; i < countPoints; i++) {
//         printf("%d ", listOfPaths->comeFrom[i]);
//     }
//      printf("\n");
// }