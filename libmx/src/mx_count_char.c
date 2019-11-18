int mx_count_char(char *str, char ch) {
    int count = 0;
    if (str == 0) return -1;
    while(*str)
        if(*str++ == ch) ++count;
    return count;
}
