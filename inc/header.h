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

void initIsOnPlace(char *isOnPlace, int count, int index);
void initComeFrom(int *comeFrom, int countPoints, int index);
unsigned long long* createMatrix(t_point *points, t_road *roads, int countRoads, int countPoints);
void initPathMas(unsigned long long *mainMatrix, t_listOfPaths *listOfPaths, int countPoints, int index);
int findMin(t_listOfPaths *pathList, int count);
void find(t_listOfOutput **output, t_listOfPaths *listOfPaths, unsigned long long *mainMatrix, int countPoints, int index);
void cpyStructure(t_listOfPaths *oldNode, t_listOfPaths *newNode, int countPoints);
#endif
