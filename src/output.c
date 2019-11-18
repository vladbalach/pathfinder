#include "header.h"

static void printfSmth(t_point*points, t_listOfOutput *tmp, int countPoints, int i) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(indexToNameOfPoint(points, countPoints, tmp->masOfOutput[0]));
    mx_printstr(" -> ");
    mx_printstr(indexToNameOfPoint(points, countPoints, tmp->masOfOutput[i]));
    mx_printstr("\nRoute ");
}

static void outputRow(t_point* points, t_road* roads, int countPoints, int countOfRoads, t_listOfOutput* tmp, int i) {
                printfSmth(points, tmp, countPoints,i);
                for(int k = 0; k <= i; k++) {
                        mx_printstr(indexToNameOfPoint(points, countPoints, tmp->masOfOutput[k]));
                        if(k + 1 <= i) mx_printstr(" -> ");
                    }
                mx_printstr("\nDistance: ");
                int sum = 0;
                int c = 0;
                for(int k = 0; k <= i; k++) {
                    if(k + 1 <= i) {
                            mx_printint(weightBetweenPoints(roads, countOfRoads, tmp->masOfOutput[k], tmp->masOfOutput[k + 1]));
                            sum += weightBetweenPoints(roads, countOfRoads, tmp->masOfOutput[k], tmp->masOfOutput[k + 1]);
                            if(k + 2 <= i) {
                                c++;
                                mx_printstr(" + ");
                            }
                    }
                }
                if(c != 0) {
                    mx_printstr(" = ");
                    mx_printint(sum);
                }
                mx_printstr("\n========================================\n");
}

void output(int index, t_point *points, t_listOfOutput *outputList, 
            int countPoints, t_road *roads, int countOfRoads) {
    t_listOfOutput *tmp = outputList;

    for(int I = index + 1; I < countPoints; I++) {
        tmp = outputList;
        while(tmp) {
            int i = 0;
            while(tmp->masOfOutput[i + 1] != -1) {
                i++;
            }
            if(tmp->masOfOutput[i] == I) {
                outputRow(points, roads, countPoints, countOfRoads, tmp, i);
            }
            tmp = tmp->next;
        }
    }
}
