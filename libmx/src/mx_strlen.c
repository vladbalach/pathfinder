int mx_strlen(const char *s) {
    if (s == 0) return 0;
    int len = 0;
    while(s[len]) {
        len++;
    }
    return len;
}
