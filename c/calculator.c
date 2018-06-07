#include<stdio.h>

double calculate_pi(int n);

int main(){
    printf( "%f",calculate_pi(100000));
    return 0;
}

double calculate_pi(int n){
    double p = 1.0,m = 0.0;
    for (int i = 1; i < n; i++) {
        m = (double) 1.0 / (double)(1 + 2 * i);
        if (i % 2 == 0) {
            p += m;
        } else {
            p -= m;
        }
    }
    return 4 * p;
}