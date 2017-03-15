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
    TreeNode<T> *Left, *Right;
    T Data;
};

template<class T>
TreeNode<T>::TreeNode() {
    Left = NULL;
    Right = NULL;
    Data = 0;
}

template<class T>
TreeNode<T>::TreeNode(T i) {
    Left = NULL;
    Right = NULL;
    Data = i;
}

template<class T>
class Tree {
public:
    Tree();

    void Insert(const T &NewData);

    int InOrder();

    int InOrder(TreeNode<T> *p);

    void Invert();

    void Invert(TreeNode<T> *p);

    void GetHeigth();

    void Graph(TreeNode<T> *p, int x, int y, int delta);

    void Graph() { Graph(Root, 320, 40, 100); }

private:
    TreeNode<T> *Root;
    int Heigth;
    int x, y;
};

template<class T>
Tree<T>::Tree() {
    Heigth = 0;
    Root = NULL;
    x = 320;
    y = 40;
}

template<class T>
void Tree<T>::Insert(const T &NewData) {
    TreeNode<T> *p, *q, *NewNode;
    if (!Root) {
        NewNode = new TreeNode<T>(NewData);
        Root = NewNode;
        return;
    }
    p = Root;
    while (p) {
        q = p;
        if (NewData < p->Data) p = p->Left;
        else if (NewData > p->Data) p = p->Right;
        else if (NewData == p->Data) {
            std::cout << "\n" << "Data Exists in The List!" << "\n";
            return;
        }
    }
    NewNode = new TreeNode<T>(NewData);

    if (NewData < q->Data) q->Left = NewNode;
    else if (NewData > q->Data) q->Right = NewNode;
}

template<class T>
int Tree<T>::InOrder(TreeNode<T> *p) {
    int a, b, max;

    if (!p) return 0;

    a = InOrder(p->Left);
    std::cout << p->Data << " ";
    b = InOrder(p->Right);
    max = (a > b) ? a : b;
    Heigth = max + 1;
    return Heigth;
}

template<class T>
int Tree<T>::InOrder() {
    InOrder(Root);
}

template<class T>
void Tree<T>::Invert(TreeNode<T> *p) {
    if (!p) return;
    TreeNode<T> *Temp;
    Temp = p->Left;
    p->Left = p->Right;
    p->Right = Temp;

    Invert(p->Left);
    Invert(p->Right);
}

template<class T>
void Tree<T>::Invert() {
    Invert(Root);
}

template<class T>
void Tree<T>::GetHeigth() {
    Heigth--;
    std::cout << Heigth << std::endl;
}

template<class T>
void Tree<T>::Graph(TreeNode<T> *p, int x, int y, int delta) {
    if (!p) return;
    char s[5];
//    itoa(p->Data, s, 10); This function is not defined in ANSI-C and is not part of C++, but is supported by some compilers.
    sprintf(s, "%d", p->Data);

//    settextstyle(2, 0, 4);
    setcolor(12);
    outtextxy(x, y, s);

    setcolor(15);
    if (p->Left) line(x - 5, y + 5, x - delta, y + 30);
    if (p->Right) line(x + 5, y + 10, x + delta, y + 30);

    Graph(p->Left, x - delta, y + 30, delta / 1.5);
    Graph(p->Right, x + delta, y + 30, delta / 1.5);

}

int main() {
    Tree<int> TreeObj;

    int i = 0;
    while (1) {
        std::cout << "Input Data:";
        std::cin >> i;
        if (i == -1) break;
        TreeObj.Insert(i);
    }
    std::cout << "Inorder Sweep: ";
    TreeObj.InOrder();
    std::cout << "\n" << "Heigth Of Tree is :";
    TreeObj.GetHeigth();
    std::cout << "Press any key to see graph of Tree...";
    std::cin.get();

    i = 0;
    initgraph(&i, &i, NULL);
//  setbkcolor(1);
    TreeObj.Graph();
    std::cout << "Press any key to continue...";
    std::cin.get();
    closegraph();
    TreeObj.Invert();
    std::cout << std::endl;
    std::cout << "Inorder sweep of inverted tree is :";
    TreeObj.InOrder();
    std::cout << "\n" << "Heigth of inverted Tree is : ";
    TreeObj.GetHeigth();

    std::cout << "Press any key to see graph of Tree...";
    std::cin.get();

    i = 0;
    initgraph(&i, &i, NULL);
//    setbkcolor(1);
    TreeObj.Graph();
    std::cout << "Program  Ended!";
    std::cin.get();

    return 0;
}
