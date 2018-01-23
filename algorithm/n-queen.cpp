#include <math.h>
#include <iostream>
using namespace std;

// N皇后问题

#define N 8

bool matrix[N + 1][N + 1] = {0};

bool IsLegal(bool matrix[N + 1][N + 1], const int &i, const int &j) {
    for (int m = 1; m <= i - 1; ++m) {
        for (int n = 1; n <= N; ++n) {
            if (matrix[m][n] == 1) {
                if (n == j || abs(i - m) == abs(j - n)) return false;
            }
        }
    }
    return true;
}

void Print(bool matrix[N + 1][N + 1]) {
    static int count = 1;
    printf("Case %d:\n", count++);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            matrix[i][j] == 1 ? printf("* ") : printf(". ");
        }
        cout << endl;
    }
    cout << endl;
}

void Trial(const int i) {
    if (i > N)
        Print(matrix);
    else
        for (int j = 1; j <= N; ++j) {
            matrix[i][j] = 1;
            if (IsLegal(matrix, i, j)) Trial(i + 1);
            matrix[i][j] = 0;
        }
}

int main(void) {
    Trial(1);
    return 0;
}
