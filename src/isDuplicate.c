#include "header.h"

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
