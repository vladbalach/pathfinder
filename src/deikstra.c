#include "header.h"

//Допилить mx_file_to_masRoads - записать веса и индексы поинтов в дороги
//NO LAST ERROR
struct s_point;
struct s_route;

//Связывающая структура, хранит знаения 
//имен и соответствующим им номерам
typedef struct s_point{
    int     nbr;
    char*   name;//allocate memory in mx)file_to_mas
    int     minDist;
    int*    minDistFrom;//index of point came from
} t_point;


typedef struct s_road {
    int nbrOfP1;
    int nbrOfP2;
    int weight;
} t_road;
//-1 if no point;
int index_of_same_point(int size, char*str, t_point *points) {
    for(int i = 0; i < size; i ++) {
            if(mx_strcmp(str, points[i].name) == 0) {
                //printf("NO = %s, index = %d\n", str, i);
                return i;
            }
        }
        return -1;
}
void output(int **matrixComeFrom, int countOfPoints, int* matrixCountWays);



/*return count of points and write all points to mas consists
  with name of point and nbr*/
int mx_file_to_masPoints(char *name, t_point **points) {

    int     fd      = 0;
    char *  str     = 0;
    int     size    = 0;

    fd = open(name, O_RDONLY);
    *points = mx_realloc(*points,sizeof(t_point) * (size));
    mx_read_line_(&str,'\n',fd);//read first line
    while(mx_read_line_(&str,'-',fd)) {//FIRST POINT
        if(index_of_same_point(size, str, *points) == -1) {
            size++;
            *points =(t_point*)mx_realloc(*points,sizeof(t_point) * (size));
            (*points)[size - 1].name = mx_strdup(str);
            (*points)[size - 1].nbr = size - 1;
            (*points)[size - 1].minDist = 2147483647;
            (*points)[size - 1].minDistFrom = malloc(sizeof(int) * 1);
            *((*points)[size - 1].minDistFrom) = -1;
        }
        mx_read_line_(&str,',',fd);//SECOND POINT
        if(index_of_same_point(size, str, *points) == -1) {
            size++;
            *points =(t_point*)mx_realloc(*points,sizeof(t_point) * (size));
            (*points)[size - 1].name = mx_strdup(str);
            (*points)[size - 1].nbr = size - 1;
            (*points)[size - 1].minDist = 2147483647;
            (*points)[size - 1].minDistFrom = malloc(sizeof(int) * 1);
            *((*points)[size - 1].minDistFrom) = -1;
        }
        mx_read_line_(&str,'\n',fd);
    }
    free(str);
    str = 0;
    return size;
}

//return index of point gets that name
int indexOfPoint(t_point **points, char * str, int count) {
    for(int i = 0; i < count; i++) {
        if(mx_strcmp((*points)[i].name,str) == 0) {
            return (*points)[i].nbr;
        }
    }
    return -1;
}

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

//transform strings roads to struct road
int mx_file_to_masRoads(char *name, t_road **roads, t_point **points, int count) {
    int     fd      = 0;
    char *  str     = 0;
    int     size    = 0;
    int index1 = 0;
    int index2 = 0;
    int weight = 0;
    fd = open(name, O_RDONLY);
    *roads = mx_realloc(*roads,sizeof(t_road) * (size));
    mx_read_line_(&str,'\n',fd);//read first line
    while(mx_read_line_(&str,'-',fd)) {//FIRST POINT
        index1 = indexOfPoint(points, str, count);
        mx_read_line_(&str,',',fd);//SECOND POINT
        index2 = indexOfPoint(points, str, count);
        mx_read_line_(&str,'\n',fd);
        weight = mx_atoi_positive_valid(str);
        //CREATE NE ROAD
        if(!haveRoad(index1, index2, weight, roads, size)) {//if have not road
            size++;
            *roads =(t_road*)mx_realloc(*roads,sizeof(t_road) * (size));
            (*roads)[size - 1].nbrOfP1 = index1;
            (*roads)[size - 1].nbrOfP2 = index2;
            (*roads)[size - 1].weight = weight;
        }
    }
    free(str);
    str = 0;
    return size;
} 

////////////////////////////////////////////
//                 ALGORITHM              //
////////////////////////////////////////////
void fillMasMinDists(t_road *roads, int countPoints, int countRoads, int* mas) {
    for(int i = 0; i < countPoints; i++) 
        for(int j = 0; j < countPoints; j++) {
             *(mas + i * countPoints + j) = -1;
             if(i == j) *(mas + i * countPoints + j) = 0;
        }
    for(int i = 0; i < countRoads; i++) {
        *(mas + roads[i].nbrOfP1 * countPoints + roads[i].nbrOfP2) = roads[i].weight;
        *(mas + roads[i].nbrOfP2 * countPoints + roads[i].nbrOfP1) = roads[i].weight;
    }
}

void initFillMasCameFrom(int countPoints, int** mas) {
    for(int i = 0; i < countPoints; i++) {
        for(int j = 0; j < countPoints; j++){
            mas[i * countPoints + j] = malloc(sizeof(int) * 1);
            mas[i * countPoints + j][0] = i;
        }
    }
}

void initFillMasOnRightPlace(int countPoints, int* mas, int index) {
    for(int i = 0; i < countPoints; i++) 
        mas[i] = -1;
    mas[index] = 1;
}

void initFillMasCountCameFrom(int *matrixCountCameFrom, int count){
    for(int i = 0; i < count; i++) 
        matrixCountCameFrom[i] = 1;
}
//return index of MIN -1 - all ways have passed
int findMin(int *masMinDist, int *onRightPlace, int countPoints,  int index) {
    int minIndex = -1;
    int minValue = 2147483647;
    for(int i = 0 ; i < countPoints;i++) {
        if((*(masMinDist + index * countPoints + i) < minValue) 
        && (*(masMinDist + index * countPoints + i) > 0)) {
            if (*(onRightPlace + i) == -1) {
                minIndex = i;
                minValue = *(masMinDist + index * countPoints + i);
            }
        }
    }
    return minIndex;
}
void deikstra(t_road *roads, int countPoints, int countRoads) {
    int* matrixCountCameFrom = malloc(sizeof(int) * countPoints * countPoints);
    int* matrixMinDists = malloc(sizeof(int) * countPoints * countPoints);
    int** matrixCameFrom = malloc(sizeof(int*) * countPoints * countPoints);
    int minIndex = -1;
    //mx_memset(matrixIsOnPlace, )
    initFillMasCountCameFrom(matrixCountCameFrom, countPoints * countPoints);
    fillMasMinDists(roads, countPoints, countRoads, matrixMinDists);
    initFillMasCameFrom(countPoints, matrixCameFrom);
    printf("INIT MAS\n");
    for(int i = 0; i < countPoints; i++) {
        for(int j = 0; j < countPoints; j++) {
            //if(*(matrixMinDists + i * countPoints + j) > 10000000) {
             //   printf("%3d",-1);
            //} else
            printf("%3d ", *(matrixMinDists + i * countPoints + j));
        }
        printf("\n");
    }
     printf("CAME FROM\n");
    for(int i = 0; i < countPoints; i++) {
        for(int j = 0; j < countPoints; j++) {
            printf("%3d ", matrixCameFrom[i * countPoints + j][0]);
        }
        printf("\n");
    }
    printf("\n");
    
    //cycle
    for(int I = 0 ; I < countPoints; I++) {
    int* onRightPlace = malloc(sizeof(int) * countPoints);
    initFillMasOnRightPlace(countPoints, onRightPlace, I);
    // printf("On RIGHT PLACE\n");
    // for(int i = 0; i < countPoints; i++) printf("%d ", onRightPlace[i]);
    
        while((minIndex = findMin(matrixMinDists, onRightPlace, countPoints, I)) != -1) {
           // printf("SAME DISTANCE %d\n", *(matrixMinDists + I * countPoints + i));
                            printf("I = %d\n", I);
                            //printf("i = %d\n", i);
                            printf("minIndex = %d\n", minIndex);
                            for(int i = 0; i < countPoints; i++) {
                                printf("%d: ",i);
                                    for(int j = 0; j < countPoints; j++) {
                                        //if(*(matrixMinDists + i * countPoints + j) > 10000000) {
                                        //    printf("%3d",-1);
                                        //} else
                                        printf("%3d ", *(matrixMinDists + i * countPoints + j));
                                    }
                                    printf("\n");
                                }
            //printf("MIN INDEX = %d\n", minIndex);
            // for(int i = 0; i < countPoints; i++) {
            //     if(onRightPlace[i] == -1) {//check only if no right place
            //         if((*(matrixMinDists + minIndex * countPoints + i) //if 0-1 + 1-2 < 0-2 
            //         + *(matrixMinDists + I * countPoints + minIndex) 
            //         < *(matrixMinDists + I * countPoints + i)) 
            //         && (*(matrixMinDists + minIndex * countPoints + i) 
            //            + *(matrixMinDists + I * countPoints + minIndex) > 0)) {
            //             *(matrixMinDists + I * countPoints + i) //0-2 = 0-1 + 1-2  
            //             = *(matrixMinDists + minIndex * countPoints + i) 
            //             + *(matrixMinDists + I * countPoints + minIndex);
            //             matrixCameFrom[I * countPoints + i][0] = minIndex;
            //         }
            //     }
            //     onRightPlace[minIndex] = 1;
            // }
            
            for(int i = 0; i < countPoints; i++) {
                if(onRightPlace[i] == -1) {//check only if no right place
                    if (*(matrixMinDists + minIndex * countPoints + i) >= 0){//if have el
                        if(
                        (*(matrixMinDists + minIndex * countPoints + i) +
                        *(matrixMinDists + I * countPoints + minIndex) 
                        < *(matrixMinDists + I * countPoints + i)) 
                        || *(matrixMinDists + I * countPoints + i) == -1
                        ) {
                        *(matrixMinDists + I * countPoints + i) = 
                        *(matrixMinDists + minIndex * countPoints + i) +
                        *(matrixMinDists + I * countPoints + minIndex);
                        matrixCameFrom[I * countPoints + i] 
                        = mx_realloc(matrixCameFrom[I * countPoints + i], sizeof(int) * 1);
                        *(matrixCountCameFrom + I * countPoints + i) = 1;
                        *(matrixCameFrom + + I * countPoints + i)[0] = minIndex;
                        } 
                        //SAME WAYS
                        else
                        {
                            if(
                        (*(matrixMinDists + minIndex * countPoints + i) +
                        *(matrixMinDists + I * countPoints + minIndex) 
                        == *(matrixMinDists + I * countPoints + i)) 
                        && (*(matrixMinDists + minIndex * countPoints + i) != -1)
                        ) {
                            (*(matrixCountCameFrom + I * countPoints + i))++;
                            matrixCameFrom[I * countPoints + i] 
                            = mx_realloc(matrixCameFrom[I * countPoints + i], sizeof(int) * 
                            *(matrixCountCameFrom + I * countPoints + i));
                            matrixCameFrom[I * countPoints + i][1] = minIndex;
                        }
                        }
                        
                        // else if( 
                        // (*(matrixMinDists + minIndex * countPoints + i) 
                        // + *(matrixMinDists + I * countPoints + minIndex)
                        // == *(matrixMinDists + I * countPoints + i))
                        // && (*(matrixMinDists + minIndex * countPoints + i) > 0)
                        // ) {
                            
                        //     (*(matrixCountCameFrom + I * countPoints + i))++;
                        //     matrixCameFrom[I * countPoints + i] 
                        //     = mx_realloc(matrixCameFrom[I * countPoints + i], sizeof(int) * 
                        //     (*(matrixCountCameFrom + I * countPoints + i)));
                        //     *(matrixCameFrom + I * countPoints + i)
                        //     [*(matrixCountCameFrom + I * countPoints + i) - 1] = minIndex;
                        // }
                    }
                }
                onRightPlace[minIndex] = 1;
            }
        }
        free(onRightPlace);
    }
    //printf("\n MIN INDEX = %d\n", minIndex);
    for(int i = 0; i < countPoints; i++) {
        for(int j = 0; j < countPoints; j++) {
            //if(*(matrixMinDists + i * countPoints + j) > 10000000) {
            //    printf("%3d",-1);
            //} else
            printf("%3d ", *(matrixMinDists + i * countPoints + j));
        }
        printf("\n");
    }

     printf("CAME FROM\n");
    for(int i = 0; i < countPoints; i++) {
        for(int j = 0; j < countPoints; j++) {
            printf("%3d ", matrixCameFrom[i * countPoints + j][0]);
        }
        printf("\n");
    }
    
    printf("COUNT OF CAE FROM\n");
    for(int i = 0; i < countPoints; i++) {
        for(int j = 0; j < countPoints; j++) {
            printf("%3d ", matrixCountCameFrom[i * countPoints + j]);
        }
        printf("\n");
    }

    printf("MATRIX OF 2 WAYS\n");
    for(int i = 0; i < countPoints; i++) {
        for(int j = 0; j < countPoints; j++) {
            if(matrixCountCameFrom[i * countPoints + j] > 1)
            printf("%3d ", matrixCameFrom[i * countPoints + j][1]);
            else printf("%3d ", -1);
        }
        printf("\n");
    }
    output(matrixCameFrom, countPoints, matrixCountCameFrom);
}
//OUTPUT/////////////////
void output(int **matrixComeFrom, int countOfPoints, int* matrixCountWays) {
    for(int i = 0 ; i < countOfPoints; i++)
    for(int j = i + 1; j < countOfPoints; j++) {
        int indexTo = i;
        int currentIndex = j;
        int layer = 1;
        // printf("%d ", i);
            printf("%d ", currentIndex);
            while(indexTo != currentIndex) {
                currentIndex = *(matrixComeFrom + countOfPoints * i + currentIndex)[layer-1];
                if(*(matrixCountWays + countOfPoints * i + currentIndex) > layer) {
                    
                    layer++;
                }
                printf("%d ", currentIndex);
            }
            printf(" FROM %d; TO %d\n", j, indexTo);
        }
            
        
}


//////////////////////
///        MAIN     //
//////////////////////


int main(int argc, char *argv[]) {
    validation(argc,argv);
    t_point *points;
    t_road *roads;
     int countRoads = 0;
    //Write all nodes to mas name - nbr
    int countPoints = mx_file_to_masPoints(argv[1], &points);
    printf("COUNT POINTS %d\n", countPoints);
    for(int i = 0; i < countPoints; i++) {
        printf("%s||%d\n",points[i].name, points[i].nbr);
    }
    int fd = open(argv[1], O_RDONLY);
    char *str = 0;
    mx_read_line_(&str,'\n',fd);//read first line
    if(mx_atoi_positive_valid(str) != countPoints) {
        mx_printerr("error: invalid number of islands");
        exit(1);
    }
    //transform file to mas Roads
    countRoads = mx_file_to_masRoads(argv[1], &roads, &points, countPoints);
    deikstra(roads, countPoints, countRoads);
    //     printf("\nPOINTS\n");
    // for(int i = 0; i < countPoints; i++) {
    //     printf("point%d [%s,%d,%d]\n", i, points[i].name, points[i].nbr, points[i].minDist);
    // }
    // printf("\nROADS\n");
    // for(int i = 0; i < countRoads; i++) {
    //     printf("road%d [%d,%d,%d]\n", i, roads[i].nbrOfP1, roads[i].nbrOfP2, roads[i].weight);
    // }

    return 0;
}
