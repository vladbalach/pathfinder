#include "header.h"

//Check the same roads A-B, B-A
bool haveRoad(int index1, int index2, int weight, t_road **roads, int count) {
    for(int i = 0; i < count; i++) {
        if(((((*roads)[i].nbrOfP1 == index1) && (*roads)[i].nbrOfP2 == index2))
        || (((*roads)[i].nbrOfP1 == index2) && ((*roads)[i].nbrOfP2 == index1))) {
            if ((*roads)[i].weight > weight) (*roads)[i].weight = weight;
            return true;//if finded
        }
    }
    return false;//not find
}
