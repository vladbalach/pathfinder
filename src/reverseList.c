#include "header.h"

void reverseList(t_listOfOutput **listOfOutput) {
    t_listOfOutput *tmp = *listOfOutput;
    while(tmp) {
        int count = 0;
        while(tmp->masOfOutput[count] != -1) {
            count++;
        } 
        for(int i = 0; i < count/2; i++) {
            int t = tmp->masOfOutput[i];
            tmp->masOfOutput[i] = tmp->masOfOutput[count - i - 1];
            tmp->masOfOutput[count - i - 1] = t;
        }
        tmp = tmp->next;
    }
}