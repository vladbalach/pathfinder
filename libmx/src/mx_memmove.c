#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *dst_ = (unsigned char*) dst;
    unsigned char *src_ = (unsigned char*) src;
    unsigned char *tmp = malloc (len);
    for(size_t i = 0; i < len; i++)
        tmp[i] = src_[i];
    for(size_t i = 0; i < len; i++)
        dst_[i] = tmp[i];
        free(tmp);
    return dst_;
}
