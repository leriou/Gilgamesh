#include <iostream>

struct tree {
    tree() { _left = _right = nullptr; }
    ~tree() {
        delete _left;
        delete _right;
    }
    tree* _left;   //左
    tree* _right;  //右
    int _value;    //值
};

std::ostream& operator<<(std::ostream& os, tree& t) {
    os << "           " << t._value << std::endl;
    os << "       /      \\" << std::endl;
    os << "     " << t._left->_value;
    os << "          " << t._right->_value << std::endl;
    os << "  /    \\      /   \\" << std::endl;
    os << "" << t._left->_left->_value;
    os << "        " << t._left->_right->_value;
    os << "   " << t._right->_left->_value;
    os << "      " << t._right->_right->_value;
    return os;
}

void CreateTreeNode(tree* head, int l, int r) {
    head->_left          = new tree;
    head->_left->_value  = l;
    head->_right         = new tree;
    head->_right->_value = r;
}

void Revert(tree* t) {
    if (!t) return;
    std::swap(t->_left, t->_right);
    Revert(t->_left);
    Revert(t->_right);
}

int main() {
    //创建二叉树
    tree head;
    head._value = 1;
    CreateTreeNode(&head, 2, 3);
    CreateTreeNode(head._left, 4, 5);
    CreateTreeNode(head._right, 6, 7);

    std::cout << "翻转前：\n" << head << "\n\n";

    //翻转二叉树
    Revert(&head);
    std::cout << "翻转后：\n" << head << "\n\n";
}
