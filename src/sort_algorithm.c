#include<stdio.h>
#include"sort_algorithm.h"
#define LEN 5

int main(){
    int a[LEN] = {10, 7, 5, 9, 4};
    insertion_sort(a);
    return 0;
}

void insertion_sort(int* array) {
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

void merge_sort(int *a){
    
}

void merge(int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1], right[n2];
    int i, j, k;

    for (i = 0; i < n1; i++) left[i] = a[start + i];
    for (j = 0; j < n2; j++) right[j] = a[mid + 1 + j];

    i = j = 0;
    k     = start;
    while (i < n1 && j < n2)
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];

    while (i < n1) a[k++] = left[i++];
    while (j < n2) a[k++] = right[j++];
}

void sort(int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        printf("sort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n", start, mid,
               mid + 1, end, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
        sort(start, mid);
        sort(mid + 1, end);
        merge(start, mid, end);
        printf("merge (%d-%d, %d-%d) to %d %d %d %d %d %d %d %d\n ", start, mid,
               mid + 1, end, a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    }
}

