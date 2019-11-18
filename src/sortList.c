#include "header.h"

void sortList(t_listOfOutput **listOfOutput, int countPoints) {
    t_listOfOutput *tmp1 = *listOfOutput;
    t_listOfOutput *tmp2 = (*listOfOutput)->next;
    t_listOfOutput *counter = *listOfOutput;
    while(counter) {
        while(tmp2) {
            for(int i = 0; i < countPoints; i++) {
                // if((tmp1->masOfOutput[i] == -1) || (tmp2->masOfOutput[i] == -1))
                //     break;
                if(tmp1->masOfOutput[i] > tmp2->masOfOutput[i]) {
                    int *tmp = tmp1->masOfOutput;
                    tmp1->masOfOutput = tmp2->masOfOutput;
                    tmp2->masOfOutput = tmp;
                    break;
                }
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        tmp1 = *listOfOutput;
        tmp2 = (*listOfOutput)->next;
        counter = counter->next;
    }
}
