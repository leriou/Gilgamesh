#include <stdio.h>
char stack[512];

int top = 0;

void push(char c) { 
    stack[top++] = c; 
}
char pop() { 
    return stack[--top]; 
}

int is_empty() { 
    return top == 0;     
}

int main() {
    push('a');
    push('b');
    push('n');
    while (!is_empty()) {
        putchar(pop());
    }
    putchar('\n');
    return 0;
}