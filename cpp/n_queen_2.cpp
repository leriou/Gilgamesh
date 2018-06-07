#include <math.h>
#include <iostream>
using namespace std;
// N 皇后问题解法2
#define N 5

static int gEightQueen[N] = {0}, gCount = 0;
void print() {
    for (int i = 0; i < N; i++) {
        int inner;
        for (inner = 0; inner < N; inner++) {
            if (inner == gEightQueen[i])
                cout << "* ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << "==========================\n";
}
int check_pos_valid(int loop, int value) {
    int index;
    int data;
    for (index = 0; index < loop; index++) {
        data = gEightQueen[index];
        if (value == data) return 0;
        if ((index + data) == (loop + value)) return 0;
        if ((index - data) == (loop - value)) return 0;
    }
    return 1;
}
void eight_queen(int index) {
    int loop;
    for (loop = 0; loop < N; loop++) {
        if (check_pos_valid(index, loop)) {
            gEightQueen[index] = loop;
            if (N - 1 == index) {
                gCount++, print();
                return;
            }
            eight_queen(index + 1);
        }
    }
}
int main() {
    eight_queen(0);
    cout << "total=" << gCount << endl;
    return 0;
}
