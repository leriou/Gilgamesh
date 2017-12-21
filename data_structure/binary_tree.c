#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left, *right;
    int val;
} node;

// 先序遍历
void f_print(node *t) {
    printf("%d \n", t->val);
    if (t->left != NULL) {
        f_print(t->left);
    }

    if (t->right != NULL) {
        f_print(t->right);
    }
}
//中序遍历
void m_print(node *t) {
    if (t->left != NULL) {
        m_print(t->left);
    }
    printf("%d \n", t->val);
    if (t->right) {
        m_print(t->right);
    }
}
//后序遍历
void b_print(node *t) {
    if (t->left != NULL) {
        b_print(t->left);
    }

    if (t->right != NULL) {
        b_print(t->right);
    }
    printf("%d \n", t->val);
}

// 搜索节点
void search(node *t, int n) {
    if (n == t->val) {
        printf("i found it : %d \n", n);
    } else {
        if (t->left != NULL) {
            search(t->left, n);
        }
        if (t->right != NULL) {
            search(t->right, n);
        }
    }
}

// 翻转二叉树
void reversal(node *t) {
    node *temp = (node *)malloc(sizeof(node));
    temp       = t->left;
    t->left    = t->right;
    t->right   = temp;
    free(temp);
    if (t->left != NULL) {
        reversal(t->left);
    }

    if (t->right != NULL) {
        reversal(t->right);
    }
}
// 创建节点
node *createNode(int i) {
    node *n  = (node *)malloc(sizeof(node));
    n->val   = i;
    n->left  = NULL;
    n->right = NULL;
    return n;
}
// 添加节点
void add(node *n, int l, int r) {
    n->left = createNode(l);
    ;
    n->right = createNode(r);
    ;
}
// 主函数
int main(void) {
    node *root = createNode(1);
    add(root, 2, 3);
    add(root->left, 4, 5);
    add(root->right, 6, 7);
    search(root, 9);

    printf("before reversal:\n");
    f_print(root);
    reversal(root);
    printf("after reversal:\n");
    f_print(root);
    return 0;
}