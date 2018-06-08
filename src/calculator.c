#include<stdio.h>
#include"calculator.h"


int main(){
    // printf( "%f",calculate_pi(100000));
    printf("%d", (int)fibonacci(20));
    return 0;
}

double calculate_pi(int n){
    double p = 1;
    return 6 * p;
}

int fibonacci(int n) {
    if (n <= 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
