/**
 * author: Vahid Mavaji
 * year: 2001
 */

#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include<stdlib.h>

template<class T>
class TreeNode {
public:
    template<class U> friend
    class Tree;

    TreeNode();

    TreeNode(T i);

private:
    TreeNode<T> *left, *right;
    T data;
};

template<class T>
TreeNode<T>::TreeNode() {
    left = NULL;
    right = NULL;
    data = 0;
}

template<class T>
TreeNode<T>::TreeNode(T i) {
    left = NULL;
    right = NULL;
    data = i;
}

template<class T>
class Tree {
public:
    Tree();

    void insert(const T &newData);

    int inOrder();

    int inOrder(TreeNode<T> *p);

    void invert();

    void invert(TreeNode<T> *p);

    void getHeigth();

    void graph(TreeNode<T> *p, int x, int y, int delta);

    void graph() { graph(root, 320, 40, 100); }

private:
    TreeNode<T> *root;
    int heigth;
    int x, y;
};

template<class T>
Tree<T>::Tree() {
    heigth = 0;
    root = NULL;
    x = 320;
    y = 40;
}

template<class T>
void Tree<T>::insert(const T &newData) {
    TreeNode<T> *p, *q, *newNode;
    if (!root) {
        newNode = new TreeNode<T>(newData);
        root = newNode;
        return;
    }
    p = root;
    while (p) {
        q = p;
        if (newData < p->data) p = p->left;
        else if (newData > p->data) p = p->right;
        else if (newData == p->data) {
            std::cout << "\n" << "Data Exists in The List!" << "\n";
            return;
        }
    }
    newNode = new TreeNode<T>(newData);

    if (newData < q->data) q->left = newNode;
    else if (newData > q->data) q->right = newNode;
}

template<class T>
int Tree<T>::inOrder(TreeNode<T> *p) {
    int a, b, max;

    if (!p) return 0;

    a = inOrder(p->left);
    std::cout << p->data << " ";
    b = inOrder(p->right);
    max = (a > b) ? a : b;
    heigth = max + 1;
    return heigth;
}

template<class T>
int Tree<T>::inOrder() {
    inOrder(root);
}

template<class T>
void Tree<T>::invert(TreeNode<T> *p) {
    if (!p) return;
    TreeNode<T> *temp;
    temp = p->left;
    p->left = p->right;
    p->right = temp;

    invert(p->left);
    invert(p->right);
}

template<class T>
void Tree<T>::invert() {
    invert(root);
}

template<class T>
void Tree<T>::getHeigth() {
    heigth--;
    std::cout << heigth << std::endl;
}

template<class T>
void Tree<T>::graph(TreeNode<T> *p, int x, int y, int delta) {
    if (!p) return;
    char s[5];
//    itoa(p->data, s, 10); This function is not defined in ANSI-C and is not part of C++, but is supported by some compilers.
    sprintf(s, "%d", p->data);

//    settextstyle(2, 0, 4);
    setcolor(12);
    outtextxy(x, y, s);

    setcolor(15);
    if (p->left) line(x - 5, y + 5, x - delta, y + 30);
    if (p->right) line(x + 5, y + 10, x + delta, y + 30);

    graph(p->left, x - delta, y + 30, delta / 1.5);
    graph(p->right, x + delta, y + 30, delta / 1.5);

}

int main() {
    Tree<int> treeObj;

    int i = 0;
    while (1) {
        std::cout << "Input Data:";
        std::cin >> i;
        if (i == -1) break;
        treeObj.insert(i);
    }
    std::cout << "Inorder Sweep: ";
    treeObj.inOrder();
    std::cout << "\n" << "Heigth Of Tree is :";
    treeObj.getHeigth();
    std::cout << "Press any key to see graph of Tree...";
    std::cin.get();

    i = 0;
    initgraph(&i, &i, NULL);
//  setbkcolor(1);
    treeObj.graph();
    std::cout << "Press any key to continue...";
    std::cin.get();
    closegraph();
    treeObj.invert();
    std::cout << std::endl;
    std::cout << "Inorder sweep of inverted tree is :";
    treeObj.inOrder();
    std::cout << "\n" << "Heigth of inverted Tree is : ";
    treeObj.getHeigth();

    std::cout << "Press any key to see graph of Tree...";
    std::cin.get();

    i = 0;
    initgraph(&i, &i, NULL);
//    setbkcolor(1);
    treeObj.graph();
    std::cout << "Program  Ended!";
    std::cin.get();

    return 0;
}
