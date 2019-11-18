int mx_count_substr(const char *str, const char *sub) {
    int i       = 0;
    int j       = 0;
    int count   = 0;

    if ((str == 0) || (sub == 0)) return - 1;
    while (str[i]) {
        j = i;
        while (str[j] == sub[j - i]) {
            if (sub[j - i + 1] == 0) count++;
            if (str[j] == 0)  return count;
            j++;
        }
        i++;
    }
    return count;
}
