#include <stdio.h>

void f(int* r, int* p, int n, int m) {
    if (m == 1) {
        for (; r != p; ++r) printf("%d ", *r);
        printf("%d\n", n);
    } else
        for (*p = 0; *p <= n; ++*p) f(r, p + 1, n - *p, m - 1);
}

void g(int n, int m) {
    int r[m];
    f(r, r, n, m);
}

int main() { g(2, 3); }
