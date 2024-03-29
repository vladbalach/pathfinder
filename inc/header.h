#ifndef header_h
#define header_h
/////////////////////////////////////
//             INCLUDES            //
/////////////////////////////////////
#include <fcntl.h>
#include "libmx.h"



/////////////////////////////////////
//            DEFINES              //
/////////////////////////////////////
#define MAX_PATH_LENGTH 1844674407370955161
#define MAX_INT 2147483647

/////////////////////////////////////
//            STRUCTURES           //
/////////////////////////////////////


//-1 if no point;
typedef struct s_listOfPaths {
    unsigned long long *path;
    int *comeFrom;
    char *isOnPlace;
    struct s_listOfPaths *next;
} t_listOfPaths;

typedef struct s_listOfOutput {
    int *masOfOutput;
    struct s_listOfOutput *next;
} t_listOfOutput;

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

// struct s_point;
// struct s_route;

// typedef struct s_route {
//     int weight;
//     struct s_point *p1;
//     struct s_point *p2;
// } t_route;

// typedef struct s_point {
//     char* name;
//     struct s_route *masRoute;
// } t_point;


/////////////////////////////////////
//           DECLARATIONS          //
/////////////////////////////////////


bool mx_is_file_empty(char* name);
int mx_read_line_(char **lineptr, char delim, const int fd);

//program
int mx_atoi_positive_valid(char *str);
void validation(int argc, char *argv[]);
bool mx_is_valid_first_line(char *str);
bool mx_is_valid_string(char* str);
//void mx_file_to_list(int fd, t_point *p_list, t_route *r_list);

//ALGORITHM
void freeList(t_listOfPaths *head);
void sortList(t_listOfOutput **listOfOutput, int countPoints);
void reverseList(t_listOfOutput **listOfOutput);

t_listOfOutput *createNode(int *data);
void pushBack(t_listOfOutput **list, int *data);
bool isDuplicate(t_listOfOutput *listOfOutput, int *mas, int countPoints);
void fillListOfOutput(t_listOfOutput **listOfOutput, t_listOfPaths *listOfPaths, int countPoints, int index);
int index_of_same_point(int size, char*str, t_point *points);
int mx_file_to_masPoints(char *name, t_point **points);
int indexOfPoint(t_point **points, char * str, int count);
bool haveRoad(int index1, int index2, int weight, t_road **roads, int count);
int mx_file_to_masRoads(char *name, t_road **roads, t_point **points, int count);
char *indexToNameOfPoint(t_point *points, int countOfPoints, int index);
int weightBetweenPoints(t_road *roads, int countOfRoads, int index1, int index2);
int lengthOfList(t_listOfOutput *list);
void output(int index, t_point *points, t_listOfOutput *outputList, int countPoints, t_road *roads, int countOfRoads);
void findShortestFor(t_point *points, t_road *roads, unsigned long long *mainMatrix, int countPoints, int countRoads, int index);
void deikstra(t_point *points, t_road *roads, int countRoads, int countPoints);
void initIsOnPlace(char *isOnPlace, int count, int index);
void initComeFrom(int *comeFrom, int countPoints, int index);
unsigned long long* createMatrix(t_road *roads, int countRoads, int countPoints);
void initPathMas(unsigned long long *mainMatrix, t_listOfPaths *listOfPaths, int countPoints, int index);
int findMin(t_listOfPaths *pathList, int count);
void find(t_listOfOutput **output, t_listOfPaths *listOfPaths, unsigned long long *mainMatrix, int countPoints, int index);
void cpyStructure(t_listOfPaths *oldNode, t_listOfPaths *newNode, int countPoints);
#endif
