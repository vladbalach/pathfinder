#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char* s_ = (unsigned char*) s;
    for (size_t i = n-1; i >= 0; i--) {
        if(s_[i] == c) {
            return &s_[i];
        }
    }
    return 0;
}
