#include<stdio.h>

int calculate(int n);

int main(){
    printf("%d",calculate(44));
    return 0;
}

int calculate(int n) {
    if (n < 2) return 1;
    return calculate(n-1) + calculate(n-2);
}