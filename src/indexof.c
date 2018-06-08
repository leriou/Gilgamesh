#include <stdio.h>

int indexof(char letter) {
    char a[] = "hello word test string";
    int i    = 0;
    while (a[i] != '\0') {
        if (a[i] == letter) return i;
        i++;
    }
    return -1;
}

int main(void) {
    printf("%d %d\n", indexof('e'), indexof('v'));
    return 0;
}
