#include "libmx.h"

 static void swap(char **el1, char** el2) {
     char* tmp = *el1;
     *el1 = *el2;
     *el2 = tmp;
 }

int mx_quicksort(char** arr, int left, int right) {
  int count = 0;
  int l = left;
  int r = right;
  int p = mx_strlen(arr[(l + r) / 2]);
  
  while (l < r)
  {
    while (mx_strlen(arr[l]) < p) l++;
    while (mx_strlen(arr[r]) > p) r--;
    if (l <= r)
    {
      if (mx_strlen(arr[l]) != mx_strlen(arr[r])) {
        swap(&arr[l], &arr[r]);
        count++;
      }
      l++;
      r--;
    }
  }

  if (left < r) count += mx_quicksort(arr, left, r);
  if (l < right) count += mx_quicksort(arr, l, right);
  return count;
}

// static void swapInt(int *a, int *b) {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }
// int mx_quicksort(char **arr, int left, int right) {
//   int l = left;
//   int r = right;
//   int p = mx_strlen(arr[left + (right - left) / 2]);
//   int count = 0;
//   while (l <= r) {
//     for(;p > mx_strlen(arr[l]);++l);
//     for(;p < mx_strlen(arr[r]);--r);
//     if(l <= r) {
//         if((l != r) && (mx_strlen(arr[l]) != mx_strlen(arr[r]))) {
//         swap(&arr[l], &arr[r]);
//         count++;
//         }
//       l++;
//       r--;
//     }
//   }
//   if (l < right) count += mx_quicksort(arr, l, right);
//   if (r > left) count += mx_quicksort(arr, left, r);
//     return count;
// }


// int mx_quicksortINT(int *arr, int left, int right) {
//     int p = arr[left];
//     int l = left;
//     int r = right;
//     int count  = 0;
//     while (l < r) {
//         while(l < r) {
//             if (p > arr[l]) l++;
//             else break;
//         }
//         while(l < r) {
//             if (p <= arr[r]) r--;//OK
//             else break;
//         }
//         if (arr[l] != arr[r]) {
//             swapInt(&arr[l],&arr[r]);
//             count++;
//             }

//             r--;
//             l++;
//     }
//     if (l < right) count += mx_quicksortINT(arr, l, right);
//     if (left < r) count += mx_quicksortINT(arr, left, right);
//     return 0;
// }
