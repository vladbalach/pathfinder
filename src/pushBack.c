#include "header.h"

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
