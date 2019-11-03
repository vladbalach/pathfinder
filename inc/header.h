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


/////////////////////////////////////
//            STRUCTURES           //
/////////////////////////////////////

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
void validation(int argc, char *argv[]);
bool mx_is_valid_first_line(char *str);
bool mx_is_valid_string(char* str);
//void mx_file_to_list(int fd, t_point *p_list, t_route *r_list);


#endif
