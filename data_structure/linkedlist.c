#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 双链表

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;
struct node* head = NULL;

node* createNode(int i) {
    node* t = (node*)malloc(sizeof(node));
    t->data = i;
    t->next = NULL;
    t->prev = NULL;
    return t;
}

void add_to_head(int i) {
    node* n = createNode(i);
    if (head == NULL) {
        head = n;
    } else {
        n->next    = head;
        head->prev = n;
        head       = n;
    }
}

void add_to_tail(int i) {
    node* n = createNode(i);
    if (head == NULL) {
        head = n;
    } else {
        node* temp = NULL;
        temp       = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
        n->next    = NULL;
        n->prev    = temp;
    }
}

void print_list(node* n) {
    node* t = n;
    while (t != NULL) {
        printf("%d \n", t->data);
        t = t->next;
    }
}

void free_list(node* n) {
    node* t    = n;
    node* temp = NULL;
    while (t != NULL) {
        temp = t->next;
        free(t);
        t = temp;
    }
}

int main(void) {
    for (int i = 0; i < 10; i++) {
        add_to_tail(i);
    }
    print_list(head);
    free_list(head);
    return 0;
}
