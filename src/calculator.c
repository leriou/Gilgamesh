#include<stdio.h>
#include<math.h>

double calculate_pi(int n){
    double p = 0.0;
    for (int i = 1; i< n;i++)
        p += (double)1/pow(i,2);
    return sqrt(6*p);
}

int fibonacci(int n);

int fibonacci(int n) {
    if (n <= 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    // printf("%d", (int)fibonacci(43));
    printf("%f",calculate_pi(100000));
    return 0;
}


