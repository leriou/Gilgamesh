#include<stdio.h>
#include<math.h>
#include"calculator.h"


int main(){
    // printf( "%f",calculate_pi(100000000));
    printf("%d", (int)fibonacci(43));
    return 0;
}

double calculate_pi(int n){
    double p = 0.0;
    for (int i = 1; i< n;i++)
        p += (double)1/pow(i,2);
    return sqrt(6*p);
}

int fibonacci(int n) {
    if (n <= 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
