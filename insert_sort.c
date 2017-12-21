#include <stdio.h>
#define LEN 5

/**
 * 插入排序
 * @author lixiumeng@gongchang.com
 * @addtime 2017-07-08T00:28:27+0800
 * @version 1.0.0
 */
void insertion_sort(int* a) {
    int i, j, key;
    for (j = 1; j < LEN; j++) {
        printf("%d,%d,%d,%d,%d\n", a[0], a[1], a[2], a[3], a[4]);
        key = a[j];
        i   = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
    printf("%d,%d,%d,%d,%d\n", a[0], a[1], a[2], a[3], a[4]);
}

int main(void) {
    int a[LEN] = {10, 7, 5, 9, 4};
    insertion_sort(a);
    return 0;
}
