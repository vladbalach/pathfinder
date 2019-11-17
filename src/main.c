#include "header.h"

//Допилить mx_file_to_masRoads - записать веса и индексы поинтов в дороги
//NO LAST ERROR


int index_of_same_point(int size, char*str, t_point *points) {
    for(int i = 0; i < size; i ++) {
            if(mx_strcmp(str, points[i].name) == 0) {
                //printf("NO = %s, index = %d\n", str, i);
                return i;
            }
        }
        return -1;
}

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


char *indexToNameOfPoint(t_point *points, int countOfPoints, int index) {
    for(int i = 0; i < countOfPoints; i++) {
        if((*(points + i)).nbr == index) {
            return (*(points + i)).name;
        }
    }
    return NULL;
}
////////////////////////////////////////////
//                 ALGORITHM              //
////////////////////////////////////////////

int lengthOfList(t_listOfOutput *list) {
    int count = 0;
    t_listOfOutput *tmp = list;
    while(tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void output(int index, t_point *points, t_listOfOutput *outputList, int countPoints) {
    for(int i = index + 1; i < countPoints; i++) {
        t_listOfOutput *tmp = outputList;
        t_listOfOutput *endList = 0;
        int len = lengthOfList(tmp);
        for(int I = len - 1; I >= 0; I--) {
            tmp = outputList;
            int J = 0;
            while(tmp) {
                if(J == I) {
                if(tmp->masOfOutput[0] == i) {
                    int j = 0;
                    
                    while(tmp->masOfOutput[j] != -1)
                        j++;
                    printf("========================================\n");
                    printf("Path: %s -> %s\n", indexToNameOfPoint(points, countPoints, tmp->masOfOutput[j-1]), 
                    indexToNameOfPoint(points, countPoints, tmp->masOfOutput[0]));
                    printf("Route: "); 
                    for(int k = j - 1; k >=0; k--) {
                        printf("%s",indexToNameOfPoint(points, countPoints, tmp->masOfOutput[k]));
                        if(k - 1 >= 0) printf(" -> ");
                    }
                    printf("\n========================================\n");
                }
                }
                J++;
                tmp = tmp->next;
            }
        }
    }
}

//FIND MIN PATHS FOR ONE ELEMENT
void findShortestFor(t_point *points,unsigned long long *mainMatrix, int countPoints, int index) {
    
    
    t_listOfPaths *listOfPaths = malloc(sizeof(t_listOfPaths));
    t_listOfOutput *outputList = 0;
    listOfPaths->next = NULL;
    listOfPaths->path = malloc(sizeof(unsigned long long) * countPoints);
    listOfPaths->comeFrom = malloc(sizeof(int) * countPoints);
    //0 - not on place; 1 - on place
    listOfPaths->isOnPlace = malloc(sizeof(char) * countPoints);
    initIsOnPlace(listOfPaths->isOnPlace, countPoints, index);
    initComeFrom(listOfPaths->comeFrom, countPoints, index);
    initPathMas(mainMatrix, listOfPaths, countPoints, index);
    
    find(&outputList, listOfPaths, mainMatrix, countPoints, index);
    output(index, points, outputList, countPoints);
    // printf("\nSPARTA!!\n");
    // t_listOfOutput *tmp = outputList;
    // while(tmp) {
    //     int i = 0;
    //     while(tmp->masOfOutput[i] != -1) {
    //         printf("%2d ",tmp->masOfOutput[i]);
    //         i++;
    //     }   
    //     printf("\n");
    //     tmp = tmp->next;
    // }
}

void deikstra(t_point *points, t_road *roads, int countRoads, int countPoints) {
    unsigned long long *mainMatrix = createMatrix(points, roads, countRoads, countPoints);
    for (int i = 0; i < countPoints; i++) 
        findShortestFor(points, mainMatrix, countPoints, i);
}

int main(int argc, char *argv[]) {
    validation(argc,argv);
    t_point *points;
    t_road *roads;
     int countRoads = 0;
    //Write all nodes to mas name - nbr
    int countPoints = mx_file_to_masPoints(argv[1], &points);
    int fd = open(argv[1], O_RDONLY);
    char *str = 0;
    mx_read_line_(&str,'\n',fd);//read first line
    if(mx_atoi_positive_valid(str) != countPoints) {
        mx_printerr("error: invalid number of islands");
        free(points);
        exit(1);
    }
    //transform file to mas Roads
    countRoads = mx_file_to_masRoads(argv[1], &roads, &points, countPoints);
    
    deikstra(points, roads, countRoads, countPoints);
    system("leaks");
    return 0;
}
