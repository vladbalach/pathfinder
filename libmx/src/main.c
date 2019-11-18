#include "../inc/libmx.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#define SIZE 9


int main() {

// int fd = open("1.txt", O_RDONLY);
//     if(fd < 0) {
//         printf("FILE ERROR ");
//         return 0;
//     }
//    char* str = 0; 
//     int status = mx_read_line(&str, '\n', fd);
//     printf("|%s|",str);
//     return 0;

printf("|%s |%d|",mx_del_extra_spaces("\f My name... is\rNeo \t\n "), mx_strlen(mx_strtrim("\f My name... is \r Neo \t\n ")));

//QSORT
    // char *arr[SIZE] = {"999999999","88888888","4444","666666","333","333","7777777","55555","88888888"};
    // //char *arr[SIZE] = {"4444","333","22","1","4444","333","22","1"};
    // //int arr[SIZE] = {8,9};
    // printf("d =%d\n", mx_quicksort(arr,0,SIZE -1));
    // for (int i = 0; i < SIZE; i++) {
    //     printf("%s ", arr[i]);
    // }
    // printf("\n");
    // return 0;

    //PRINT UNICODE
    //mx_print_unicode(0x17D8);

    //PRINTF STR ARR
    // char *arr[] = {"Hello world", "My name is Vlad!", "London", "is the capital", "of Great Britain", 0};
    // char str[] = "___";
    // mx_print_strarr(arr, &str[0]);

    //PRINTF INT
    // mx_printint(-9896978);

    //POW 
    // printf("%f\n", mx_pow(180,2));

    //SQRT
    // printf("%d \n",mx_sqrt(mx_pow(180,2)));

    //NBR TO HEX
    // printf("%s \n", mx_nbr_to_hex(12));

    //HEX TO NBR
    // printf("%lu \n", mx_hex_to_nbr("ffd"));

    //ITOA
    // char *str = 0;
    // printf("%s",str = mx_itoa(-123123));

    //FOR EACH
    // int arr[] = {1,5,7,3,444,-4};
    // mx_foreach(arr, 6, mx_printint);


// int fd1 = 0;
//      fd1 = open("GoT.txt", O_RDONLY);
     //printf("%s", mx_file_to_str("GoT.txt"));
    // //READ LINE
    // int fd1 = 0;
    // fd1 = open("GoT.txt", O_RDONLY);
    // char *str = 0; 
    // int count = 0;
    // //int fd2 = open("2.txt", O_RDONLY);
    // while((count = mx_read_line(&str, 1000, ' ', fd1)) > 0){
    //     printf("%d | %s\n",count, str);
    // }
    // printf("%s\n", str);
    // while(mx_read_line(&str, 5, ' ',fd1) != 0) {
    //     printf("%s \n", str);
    // }
    

    //STR SPLIT
    // char **str = 0; 
    // int i = 0;
    // str = mx_strsplit("Hello! World, i am here!", ' ');
    // while ( str[i])  {
    //   printf("%s\n", str[i++]);
    // }
    // char *name = "\f My\f\rname... is \r Neo \t\n ";
    // printf("%s\n", mx_del_extra_spaces(name)); //returns "My name... is Neo"
    // //REPLACE 
    // char *str = mx_replace_substr("12345634 3434 34", "34", "artdj'reoakjt'okaerjt'kaerjt'oaeijrt[oi'rjea'tijera'tij'areoijt'aoeirjtoa'r");
    // printf("%s\n",str);

    //MEMSET
    // char str[100];
    // mx_memset(str, 'X', 11);
    // printf("%s", str);

    //MEM CPY
    // char str1[10] = "Hello!\0";
    // char str2[10];
    // printf("%s\n",mx_memcpy(str2, str1, 5));

    //MEM C CPY
    //  char str1[10] = "Hello!\0";
    //  char str2[10];
    //  printf("%s\n",mx_memccpy(str2, str1, 'l',5));
    //  printf("%s\n",memccpy(str2, str1, 'l',5));

    // char *str1 = malloc(10);
    // strcpy(str1, "1234567890");
    // char *str2 = malloc(10);
    // strcpy(str2, str1);
    // printf("%s", memccpy(str1, str2, '4', 1));

    // // char *str1 = malloc(10);
    // strcpy(str1, "123456789");
    // char *str2 = malloc(10);
    // char *str3 = mx_memccpy(str2, str1,'4',10);
    // strcpy(str3, "_=_");
    // printf("s = %s\n",mx_memccpy(str2, str1,'4',10));
    //  printf("s = %s",str2);
    //MEM CMP
    // char str1[10] = "H";
    // char str2[10] = "b";
    // printf("%d\n",mx_memcmp(str1, str2, 10));
    
    //MEM CHAR
    // printf("%s",mx_memchr("Hello!",',',12));

    //MEM R CHAR 
    //  printf("%s", mx_memrchr("Helolo!",'l',7));

    //MEMMEM
    // printf("%s", mx_memmem("Whaft a function!", 15, "func_", 5));

    //MEM MOVE
    // char str[10] = "123456789";
    // printf("%s\n", mx_memmove(&str[1],&str[2],3));

    //REALLOC
//     printf("\nREALLOC\n\n");

//     int *p3 = 0;
//     //p3[0] = 1;
//     //mx_strcpy(p3, "0123456789");
//     //char *p4 = malloc(10);
//     strcpy(p3,"1234");
//     p3 = (int*)mx_realloc(p3,19);
//    // printf("%s\n", p);
//     //printf("%s\n", p3);
//     for(int i = 0; i < 19; i++) {
//         printf("%d ", p3[i]);
//     }

    ////////////////////////////////////////////
    //               LIST PACK                //
    ////////////////////////////////////////////

    //PUSH FRONT
    // t_list *list = 0;
    // mx_push_front(&list, "1");
    // mx_push_front(&list, "2");
    // mx_push_front(&list, "3");
    // t_list *tmp = list;
    // while(tmp) {
    //     printf("%s\n",tmp->data);
    //     tmp = tmp->next;
    // }    


    //PUSH BACK
    // t_list *list = 0;
    // mx_push_front(&list, "1");
    // mx_push_front(&list, "2");
    //  mx_push_back(&list, "3");
    // t_list *tmp = list;
    // while(tmp) {
    //     printf("%s\n",tmp->data);
    //     tmp = tmp->next;
    // }

    //POP FRONT
    // t_list *list = 0;
    // mx_push_front(&list, "1");
    // mx_push_front(&list, "2");
    // mx_push_front(&list, "3");
    // mx_push_front(&list, "4");
    // mx_pop_front(&list);
    // t_list *tmp = list;
    // while(tmp) {
    //     printf("%s\n",tmp->data);
    //     tmp = tmp->next;
    // }

    //POP BACK 
    // t_list *list = 0;
    // mx_push_front(&list, "1");
    // mx_push_front(&list, "2");
    // mx_push_front(&list, "3");
    // mx_push_front(&list, "4");
    // mx_push_front(&list, "5");
    // mx_push_front(&list, "6");
    // mx_pop_front(&list);
    // mx_pop_front(&list);
    // mx_pop_front(&list);
    // mx_pop_front(&list);
    // mx_pop_front(&list);
    // mx_pop_front(&list);
    // mx_pop_front(&list);
    // mx_pop_front(&list);
    // t_list *tmp = list;
    // while(tmp) {
    //     printf("%s\n",tmp->data);
    //     tmp = tmp->next;
    // }
    // printf("%d",list);

    //LIST SIZE
    // t_list *list = 0;
    // t_list *tmp = list;
    // while(tmp) {
    //     printf("%s\n",tmp->data);
    //     tmp = tmp->next;
    // }
    // printf ("%d", mx_list_size(list));


    //LIST SORT
    // t_list *list = 0;
    // int a = 1;
    // int b = 4;
    // int c = 2;
    // int d = -1;
    // int e = 3;
    // mx_push_front(&list, &a);
    // mx_push_front(&list, &b);
    // mx_push_front(&list, &c);
    // mx_push_front(&list, &d);
    // //mx_pop_back(&list);
    // mx_push_front(&list, &e);
    // //  mx_pop_back(&list);
    // //   mx_pop_back(&list);
    // t_list *tmp = list;
    // while(tmp) {
    //     printf("1 = %d\n",*((int*)tmp->data));
    //     tmp = tmp->next;
    // }  
    // printf("\n");
    // mx_sort_list(list,cmpare);
    // tmp = list;
    //  while(tmp) {
    //     printf("2 = %d\n",*((int*)tmp->data));
    //     tmp = tmp->next;
    // }   
    // system("leaks -q a.out");
    // char *s = (char *) malloc(5 *sizeof(char));
    // s[0] = 's';
    // s[1] = 'y';
    // s[2] = 'k';
    // s[3] = 'a';
    // s[4] = '\0';
    // printf("%s\n", s);
    // s = realloc(s, 2);
    // printf("%s\n", s);
    return 0;
}
