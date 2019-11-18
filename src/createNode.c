#include "header.h"

t_listOfOutput *createNode(int *data) {
    t_listOfOutput *newNode = (t_listOfOutput*) malloc (sizeof(t_listOfOutput));
    newNode->masOfOutput = data;
    newNode->next = 0;
    return newNode;
}
