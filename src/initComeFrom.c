void initComeFrom(int *comeFrom, int countPoints, int index) {
    for(int i = 0; i < countPoints; i++) {
        comeFrom[i] = -1;
    }
    comeFrom[index] = index;
}
