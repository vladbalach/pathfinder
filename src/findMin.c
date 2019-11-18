#include "header.h"

//find min in mas
//return index of min or -1 if all done
int findMin(t_listOfPaths *pathList, int count) {
    int minI = 0;
    unsigned long long min = MAX_PATH_LENGTH;
 for(int i = 0; i < count; i++) {
     if((pathList->path[i] < min) && (pathList->isOnPlace[i] == 0)){
         minI = i;
         min = pathList->path[i];
     }
 }

return min < MAX_PATH_LENGTH ? minI : -1;
}
