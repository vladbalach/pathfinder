#include "libmx.h"

static void printOneCase(int num, int headA, int headB, int I) {
    char  ch = 0;
    for(int i = I; i >=  0; i--) {
           ch = 0;
          if(i == I) {
             ch = (char) ((num >> (6 * i)) & headA) | headB;
          } else {
             ch = (char) ((num >> (6 * i)) & 63) | 128;
          }
          write(1, &ch, 1);
       } 
 }

void mx_print_unicode(wchar_t c) {
    int num = (int) c;
if (num < 128) {
    char ch = (char) (c);
    write(1,&ch,1);
}
else if (c < 2048) {
    printOneCase(num, 31, 192, 1);
}
else if (c < 65536) {
    printOneCase(num, 15, 224, 2);
}
else {
    printOneCase(num, 7, 240, 3);
}
}
// void mx_print_unicode(wchar_t c) {
//    int num = (int) c;
   

//    for(int i = 3; i >=  0; i--) {
//           ch = 0;
//          if(i == 3) {
//             ch = (char) ((num >> (6 * i)) & 7) | 240;
//          } else {
//             ch = (char) ((num >> (6 * i)) & 63) | 128;
//          }
//          write(1, &ch, 1);
//       } 





   // if (c < 128)
   // {
   // char ch = (char) (c);
   // write(1,&ch,1);
   // } else if(c < 2048) {
   //    for(int i = 1; i >= 0; i--) {
   //       ch = 0;
   //    if(i == 1) {
   //       ch = (char) ((num >> (6 * i)) & 31) | 192;
   //    } else {
   //       ch = (((char)num >> (6 * i)) & 63) | 128;
   //    }
   //    write(1, &ch, 1);
   //    } 
   // }
   // else if(c < 65536) {
   //    for(int i = 2; i >=  0; i--) {
   //        ch = 0;
   //    if(i == 2) {
   //       ch = (char)((num >> (6 * i)) & 15) | 224;
   //    } else {
   //       ch = (char)((num >> (6 * i)) & 63) | 128;
   //    }
   //    write(1, &ch, 1);
   //    } 
   // }
   // else {
   //    printf("C");
   //    for(int i = 3; i >=  0; i--) {
   //        ch = 0;
   //       if(i == 3) {
   //          ch = (char) ((num >> (6 * i)) & 7) | 240;
   //       } else {
   //          ch = (char) ((num >> (6 * i)) & 63) | 128;
   //       }
   //       write(1, &ch, 1);
   //    } 
   // }
//}

