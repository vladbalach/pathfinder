#include "header.h"

int lengthOfList(t_listOfOutput *list) {
    int count = 0;
    t_listOfOutput *tmp = list;
    while(tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
