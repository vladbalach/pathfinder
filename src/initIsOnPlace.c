#include "header.h"

void initIsOnPlace(char *isOnPlace, int count, int index) {
    for(int i = 0; i < count; i++) {
        isOnPlace[i] = 0;
    }
    if(index < count) {
        isOnPlace[index] = 1;
    }
}
